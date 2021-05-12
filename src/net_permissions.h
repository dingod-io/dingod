// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_NET_PERMISSIONS_H
#define BITCOIN_NET_PERMISSIONS_H

#include <netaddress.h>

#include <string>
#include <type_traits>
#include <vector>

struct bilingual_str;

extern const std::vector<std::string> NET_PERMISSIONS_DOC;

enum class NetPermissionFlags : uint32_t {
    PF_NONE = 0,
    // Can query bloomfilter even if -peerbloomfilters is false
    PF_BLOOMFILTER = (1U << 1),
    // Relay and accept transactions from this peer, even if -blocksonly is true
    // This peer is also not subject to limits on how many transaction INVs are
    // tracked
    PF_RELAY = (1U << 3),
    // Always relay transactions from this peer, even if already in mempool
    // Keep parameter interaction: forcerelay implies relay
    PF_FORCERELAY = (1U << 2) | PF_RELAY,
    // Allow getheaders during IBD and block-download after maxuploadtarget
    // limit
    PF_DOWNLOAD = (1U << 6),
    // Can't be banned/disconnected/discouraged for misbehavior
    PF_NOBAN = (1U << 4) | PF_DOWNLOAD,
    // Can query the mempool
    PF_MEMPOOL = (1U << 5),
    // Can request addrs without hitting a privacy-preserving cache, and send us
    // unlimited amounts of addrs.
    PF_ADDR = (1U << 7),
    // Bypass the limit on how many proof INVs are tracked from this peer as
    // well as the delay penalty when reaching the the in-flight requests limit
    PF_BYPASS_PROOF_REQUEST_LIMITS = (1U << 30),

    // True if the user did not specifically set fine grained permissions
    PF_ISIMPLICIT = (1U << 31),
    PF_ALL = PF_BLOOMFILTER | PF_FORCERELAY | PF_RELAY | PF_NOBAN | PF_MEMPOOL |
             PF_DOWNLOAD | PF_BYPASS_PROOF_REQUEST_LIMITS | PF_ADDR,
};
static inline constexpr NetPermissionFlags operator|(NetPermissionFlags a,
                                                     NetPermissionFlags b) {
    using t = typename std::underlying_type<NetPermissionFlags>::type;
    return static_cast<NetPermissionFlags>(static_cast<t>(a) |
                                           static_cast<t>(b));
}

class NetPermissions {
public:
    NetPermissionFlags m_flags;
    static std::vector<std::string> ToStrings(NetPermissionFlags flags);
    static inline bool HasFlag(NetPermissionFlags flags, NetPermissionFlags f) {
        using t = typename std::underlying_type<NetPermissionFlags>::type;
        return (static_cast<t>(flags) & static_cast<t>(f)) == static_cast<t>(f);
    }
    static inline void AddFlag(NetPermissionFlags &flags,
                               NetPermissionFlags f) {
        flags = flags | f;
    }
    //! ClearFlag is only called with `f` == NetPermissionFlags::PF_ISIMPLICIT.
    //! If that should change in the future, be aware that ClearFlag should not
    //! be called with a subflag of a multiflag, e.g.
    //! NetPermissionFlags::PF_RELAYor NetPermissionFlags::PF_DOWNLOAD, as that
    //! would leave `flags` in an invalid state corresponding to none of the
    //! existing flags.
    static inline void ClearFlag(NetPermissionFlags &flags,
                                 NetPermissionFlags f) {
        assert(f == NetPermissionFlags::PF_ISIMPLICIT);
        using t = typename std::underlying_type<NetPermissionFlags>::type;
        flags = static_cast<NetPermissionFlags>(static_cast<t>(flags) &
                                                ~static_cast<t>(f));
    }
};

class NetWhitebindPermissions : public NetPermissions {
public:
    static bool TryParse(const std::string str, NetWhitebindPermissions &output,
                         bilingual_str &error);
    CService m_service;
};

class NetWhitelistPermissions : public NetPermissions {
public:
    static bool TryParse(const std::string str, NetWhitelistPermissions &output,
                         bilingual_str &error);
    CSubNet m_subnet;
};

#endif // BITCOIN_NET_PERMISSIONS_H
