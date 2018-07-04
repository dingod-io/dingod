// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <script/sign.h>

#include <key.h>
#include <policy/policy.h>
#include <primitives/transaction.h>
#include <script/standard.h>
#include <uint256.h>

typedef std::vector<uint8_t> valtype;

MutableTransactionSignatureCreator::MutableTransactionSignatureCreator(
    const CMutableTransaction *txToIn, unsigned int nInIn,
    const Amount &amountIn, SigHashType sigHashTypeIn)
    : txTo(txToIn), nIn(nInIn), amount(amountIn), sigHashType(sigHashTypeIn),
      checker(txTo, nIn, amountIn) {}

bool MutableTransactionSignatureCreator::CreateSig(
    const SigningProvider &provider, std::vector<uint8_t> &vchSig,
    const CKeyID &address, const CScript &scriptCode) const {
    CKey key;
    if (!provider.GetKey(address, key)) {
        return false;
    }

    uint256 hash = SignatureHash(scriptCode, *txTo, nIn, sigHashType, amount);
    if (!key.SignECDSA(hash, vchSig)) {
        return false;
    }

    vchSig.push_back(uint8_t(sigHashType.getRawSigHashType()));
    return true;
}

/**
 * Sign scriptPubKey using signature made with creator.
 * Signatures are returned in scriptSigRet (or returns false if scriptPubKey
 * can't be signed), unless whichTypeRet is TX_SCRIPTHASH, in which case
 * scriptSigRet is the redemption script.
 * Returns false if scriptPubKey could not be completely satisfied.
 */
static bool SignStep(const SigningProvider &provider,
                     const BaseSignatureCreator &creator,
                     const CScript &scriptPubKey, std::vector<valtype> &ret,
                     txnouttype &whichTypeRet) {
    CScript scriptRet;
    uint160 h160;
    ret.clear();
    std::vector<uint8_t> sig;

    std::vector<valtype> vSolutions;
    if (!Solver(scriptPubKey, whichTypeRet, vSolutions)) {
        return false;
    }

    switch (whichTypeRet) {
        case TX_NONSTANDARD:
        case TX_NULL_DATA:
            return false;
        case TX_PUBKEY:
            if (!creator.CreateSig(provider, sig,
                                   CPubKey(vSolutions[0]).GetID(),
                                   scriptPubKey)) {
                return false;
            }
            ret.push_back(std::move(sig));
            return true;
        case TX_PUBKEYHASH: {
            CKeyID keyID = CKeyID(uint160(vSolutions[0]));
            if (!creator.CreateSig(provider, sig, keyID, scriptPubKey)) {
                return false;
            }
            ret.push_back(std::move(sig));
            CPubKey pubkey;
            provider.GetPubKey(keyID, pubkey);
            ret.push_back(ToByteVector(pubkey));
            return true;
        }
        case TX_SCRIPTHASH:
            if (provider.GetCScript(uint160(vSolutions[0]), scriptRet)) {
                ret.push_back(
                    std::vector<uint8_t>(scriptRet.begin(), scriptRet.end()));
                return true;
            }
            return false;
        case TX_MULTISIG: {
            size_t required = vSolutions.front()[0];
            // workaround CHECKMULTISIG bug
            ret.push_back(valtype());
            for (size_t i = 1; i < vSolutions.size() - 1; ++i) {
                CPubKey pubkey = CPubKey(vSolutions[i]);
                if (ret.size() < required + 1 &&
                    creator.CreateSig(provider, sig, pubkey.GetID(),
                                      scriptPubKey)) {
                    ret.push_back(std::move(sig));
                }
            }
            bool ok = ret.size() == required + 1;
            for (size_t i = 0; i + ret.size() < required + 1; ++i) {
                ret.push_back(valtype());
            }
            return ok;
        }
        default:
            return false;
    }
}

static CScript PushAll(const std::vector<valtype> &values) {
    CScript result;
    for (const valtype &v : values) {
        if (v.size() == 0) {
            result << OP_0;
        } else if (v.size() == 1 && v[0] >= 1 && v[0] <= 16) {
            result << CScript::EncodeOP_N(v[0]);
        } else {
            result << v;
        }
    }

    return result;
}

bool ProduceSignature(const SigningProvider &provider,
                      const BaseSignatureCreator &creator,
                      const CScript &fromPubKey, SignatureData &sigdata) {
    if (sigdata.complete) {
        return true;
    }

    std::vector<valtype> result;
    txnouttype whichType;
    bool solved = SignStep(provider, creator, fromPubKey, result, whichType);
    CScript subscript;

    if (solved && whichType == TX_SCRIPTHASH) {
        // Solver returns the subscript that needs to be evaluated; the final
        // scriptSig is the signatures from that and then the serialized
        // subscript:
        subscript = CScript(result[0].begin(), result[0].end());
        solved = solved &&
                 SignStep(provider, creator, subscript, result, whichType) &&
                 whichType != TX_SCRIPTHASH;
        result.push_back(
            std::vector<uint8_t>(subscript.begin(), subscript.end()));
    }

    sigdata.scriptSig = PushAll(result);

    // Test solution
    sigdata.complete =
        solved && VerifyScript(sigdata.scriptSig, fromPubKey,
                               STANDARD_SCRIPT_VERIFY_FLAGS, creator.Checker());
    return sigdata.complete;
}

class SignatureExtractorChecker final : public BaseSignatureChecker {
private:
    SignatureData &sigdata;
    BaseSignatureChecker &checker;

public:
    SignatureExtractorChecker(SignatureData &sigdata_,
                              BaseSignatureChecker &checker_)
        : sigdata(sigdata_), checker(checker_) {}
    bool CheckSig(const std::vector<uint8_t> &scriptSig,
                  const std::vector<uint8_t> &vchPubKey,
                  const CScript &scriptCode, uint32_t flags) const override;
};

bool SignatureExtractorChecker::CheckSig(const std::vector<uint8_t> &scriptSig,
                                         const std::vector<uint8_t> &vchPubKey,
                                         const CScript &scriptCode,
                                         uint32_t flags) const {
    if (checker.CheckSig(scriptSig, vchPubKey, scriptCode, flags)) {
        CPubKey pubkey(vchPubKey);
        sigdata.signatures.emplace(pubkey.GetID(), SigPair(pubkey, scriptSig));
        return true;
    }
    return false;
}

namespace {
struct Stacks {
    std::vector<valtype> script;

    Stacks() {}
    explicit Stacks(const std::vector<valtype> &scriptSigStack_)
        : script(scriptSigStack_) {}
    explicit Stacks(const SignatureData &data) {
        EvalScript(script, data.scriptSig, MANDATORY_SCRIPT_VERIFY_FLAGS,
                   BaseSignatureChecker());
    }

    SignatureData Output() const {
        SignatureData result;
        result.scriptSig = PushAll(script);
        return result;
    }
};
} // namespace

// Extracts signatures and scripts from incomplete scriptSigs. Please do not
// extend this, use PSBT instead
SignatureData DataFromTransaction(const CMutableTransaction &tx,
                                  unsigned int nIn, const CTxOut &txout) {
    SignatureData data;
    assert(tx.vin.size() > nIn);
    data.scriptSig = tx.vin[nIn].scriptSig;
    Stacks stack(data);

    // Get signatures
    MutableTransactionSignatureChecker tx_checker(&tx, nIn, txout.nValue);
    SignatureExtractorChecker extractor_checker(data, tx_checker);
    if (VerifyScript(data.scriptSig, txout.scriptPubKey,
                     STANDARD_SCRIPT_VERIFY_FLAGS, extractor_checker)) {
        data.complete = true;
        return data;
    }

    // Get scripts
    txnouttype script_type;
    std::vector<std::vector<uint8_t>> solutions;
    Solver(txout.scriptPubKey, script_type, solutions);
    CScript next_script = txout.scriptPubKey;

    if (script_type == TX_SCRIPTHASH && !stack.script.empty() &&
        !stack.script.back().empty()) {
        // Get the redeemScript
        CScript redeem_script(stack.script.back().begin(),
                              stack.script.back().end());
        data.redeem_script = redeem_script;
        next_script = std::move(redeem_script);

        // Get redeemScript type
        Solver(next_script, script_type, solutions);
        stack.script.pop_back();
    }
    if (script_type == TX_MULTISIG && !stack.script.empty()) {
        // Build a map of pubkey -> signature by matching sigs to pubkeys:
        assert(solutions.size() > 1);
        unsigned int num_pubkeys = solutions.size() - 2;
        unsigned int last_success_key = 0;
        for (const valtype &sig : stack.script) {
            for (unsigned int i = last_success_key; i < num_pubkeys; ++i) {
                const valtype &pubkey = solutions[i + 1];
                // We either have a signature for this pubkey, or we have found
                // a signature and it is valid
                if (data.signatures.count(CPubKey(pubkey).GetID()) ||
                    extractor_checker.CheckSig(sig, pubkey, next_script,
                                               STANDARD_SCRIPT_VERIFY_FLAGS)) {
                    last_success_key = i + 1;
                    break;
                }
            }
        }
    }

    return data;
}

void UpdateInput(CTxIn &input, const SignatureData &data) {
    input.scriptSig = data.scriptSig;
}

bool SignSignature(const SigningProvider &provider, const CScript &fromPubKey,
                   CMutableTransaction &txTo, unsigned int nIn,
                   const Amount amount, SigHashType sigHashType) {
    assert(nIn < txTo.vin.size());

    MutableTransactionSignatureCreator creator(&txTo, nIn, amount, sigHashType);

    SignatureData sigdata;
    bool ret = ProduceSignature(provider, creator, fromPubKey, sigdata);
    UpdateInput(txTo.vin.at(nIn), sigdata);
    return ret;
}

bool SignSignature(const SigningProvider &provider, const CTransaction &txFrom,
                   CMutableTransaction &txTo, unsigned int nIn,
                   SigHashType sigHashType) {
    assert(nIn < txTo.vin.size());
    CTxIn &txin = txTo.vin[nIn];
    assert(txin.prevout.GetN() < txFrom.vout.size());
    const CTxOut &txout = txFrom.vout[txin.prevout.GetN()];

    return SignSignature(provider, txout.scriptPubKey, txTo, nIn, txout.nValue,
                         sigHashType);
}

static std::vector<valtype> CombineMultisig(
    const CScript &scriptPubKey, const BaseSignatureChecker &checker,
    const std::vector<valtype> &vSolutions, const std::vector<valtype> &sigs1,
    const std::vector<valtype> &sigs2) {
    // Combine all the signatures we've got:
    std::set<valtype> allsigs;
    for (const valtype &v : sigs1) {
        if (!v.empty()) {
            allsigs.insert(v);
        }
    }

    for (const valtype &v : sigs2) {
        if (!v.empty()) {
            allsigs.insert(v);
        }
    }

    // Build a map of pubkey -> signature by matching sigs to pubkeys:
    assert(vSolutions.size() > 1);
    unsigned int nSigsRequired = vSolutions.front()[0];
    unsigned int nPubKeys = vSolutions.size() - 2;
    std::map<valtype, valtype> sigs;
    for (const valtype &sig : allsigs) {
        for (unsigned int i = 0; i < nPubKeys; i++) {
            const valtype &pubkey = vSolutions[i + 1];
            // Already got a sig for this pubkey
            if (sigs.count(pubkey)) {
                continue;
            }

            if (checker.CheckSig(sig, pubkey, scriptPubKey,
                                 STANDARD_SCRIPT_VERIFY_FLAGS)) {
                sigs[pubkey] = sig;
                break;
            }
        }
    }
    // Now build a merged CScript:
    unsigned int nSigsHave = 0;
    // pop-one-too-many workaround
    std::vector<valtype> result;
    result.push_back(valtype());
    for (unsigned int i = 0; i < nPubKeys && nSigsHave < nSigsRequired; i++) {
        if (sigs.count(vSolutions[i + 1])) {
            result.push_back(sigs[vSolutions[i + 1]]);
            ++nSigsHave;
        }
    }

    // Fill any missing with OP_0:
    for (unsigned int i = nSigsHave; i < nSigsRequired; i++) {
        result.push_back(valtype());
    }

    return result;
}

static Stacks CombineSignatures(const CScript &scriptPubKey,
                                const BaseSignatureChecker &checker,
                                const txnouttype txType,
                                const std::vector<valtype> &vSolutions,
                                Stacks sigs1, Stacks sigs2) {
    switch (txType) {
        case TX_NONSTANDARD:
        case TX_NULL_DATA:
            // Don't know anything about this, assume bigger one is correct:
            if (sigs1.script.size() >= sigs2.script.size()) {
                return sigs1;
            }

            return sigs2;
        case TX_PUBKEY:
        case TX_PUBKEYHASH:
            // Signatures are bigger than placeholders or empty scripts:
            if (sigs1.script.empty() || sigs1.script[0].empty()) {
                return sigs2;
            }

            return sigs1;
        case TX_SCRIPTHASH: {
            if (sigs1.script.empty() || sigs1.script.back().empty()) {
                return sigs2;
            }

            if (sigs2.script.empty() || sigs2.script.back().empty()) {
                return sigs1;
            }

            // Recur to combine:
            valtype spk = sigs1.script.back();
            CScript pubKey2(spk.begin(), spk.end());

            txnouttype txType2;
            std::vector<std::vector<uint8_t>> vSolutions2;
            Solver(pubKey2, txType2, vSolutions2);
            sigs1.script.pop_back();
            sigs2.script.pop_back();
            Stacks result = CombineSignatures(pubKey2, checker, txType2,
                                              vSolutions2, sigs1, sigs2);
            result.script.push_back(spk);
            return result;
        }
        case TX_MULTISIG:
            return Stacks(CombineMultisig(scriptPubKey, checker, vSolutions,
                                          sigs1.script, sigs2.script));
        default:
            return Stacks();
    }
}

SignatureData CombineSignatures(const CScript &scriptPubKey,
                                const BaseSignatureChecker &checker,
                                const SignatureData &scriptSig1,
                                const SignatureData &scriptSig2) {
    txnouttype txType;
    std::vector<std::vector<uint8_t>> vSolutions;
    Solver(scriptPubKey, txType, vSolutions);

    return CombineSignatures(scriptPubKey, checker, txType, vSolutions,
                             Stacks(scriptSig1), Stacks(scriptSig2))
        .Output();
}

namespace {
/** Dummy signature checker which accepts all signatures. */
class DummySignatureChecker final : public BaseSignatureChecker {
public:
    DummySignatureChecker() {}
    bool CheckSig(const std::vector<uint8_t> &scriptSig,
                  const std::vector<uint8_t> &vchPubKey,
                  const CScript &scriptCode, uint32_t flags) const override {
        return true;
    }
};
const DummySignatureChecker DUMMY_CHECKER;

class DummySignatureCreator final : public BaseSignatureCreator {
public:
    DummySignatureCreator() {}
    const BaseSignatureChecker &Checker() const override {
        return DUMMY_CHECKER;
    }
    bool CreateSig(const SigningProvider &provider,
                   std::vector<uint8_t> &vchSig, const CKeyID &keyid,
                   const CScript &scriptCode) const override {
        // Create a dummy signature that is a valid DER-encoding
        vchSig.assign(72, '\000');
        vchSig[0] = 0x30;
        vchSig[1] = 69;
        vchSig[2] = 0x02;
        vchSig[3] = 33;
        vchSig[4] = 0x01;
        vchSig[4 + 33] = 0x02;
        vchSig[5 + 33] = 32;
        vchSig[6 + 33] = 0x01;
        vchSig[6 + 33 + 32] = SIGHASH_ALL | SIGHASH_FORKID;
        return true;
    }
};
} // namespace

const BaseSignatureCreator &DUMMY_SIGNATURE_CREATOR = DummySignatureCreator();
