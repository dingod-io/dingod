/**
 * @generated by contrib/devtools/chainparams/generate_chainparams_constants.py
 */

#include <chainparamsconstants.h>

namespace ChainParamsConstants {
    const BlockHash MAINNET_DEFAULT_ASSUME_VALID = BlockHash::fromHex("000000000000000006e72d95ee03053dd129b1433a91afd1b890d8a9dcd75ab1");
    const uint256 MAINNET_MINIMUM_CHAIN_WORK = uint256S("000000000000000000000000000000000000000001683916da941fc5c035b07b");
    const uint64_t MAINNET_ASSUMED_BLOCKCHAIN_SIZE = 211;
    const uint64_t MAINNET_ASSUMED_CHAINSTATE_SIZE = 3;

    const BlockHash TESTNET_DEFAULT_ASSUME_VALID = BlockHash::fromHex("0000000000097f4ca1a8f8ff9e99e471c9b3dc5e786b13951e3ecb6698f846a8");
    const uint256 TESTNET_MINIMUM_CHAIN_WORK = uint256S("00000000000000000000000000000000000000000000006e9d3e958f413766c6");
    const uint64_t TESTNET_ASSUMED_BLOCKCHAIN_SIZE = 55;
    const uint64_t TESTNET_ASSUMED_CHAINSTATE_SIZE = 2;
} // namespace ChainParamsConstants

