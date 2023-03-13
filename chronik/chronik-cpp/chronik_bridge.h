// Copyright (c) 2022 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CHRONIK_CPP_CHRONIK_BRIDGE_H
#define BITCOIN_CHRONIK_CPP_CHRONIK_BRIDGE_H

#include <memory>
#include <rust/cxx.h>

class CBlock;
class CBlockIndex;

namespace node {
struct NodeContext;
} // namespace node
class uint256;

namespace chronik_bridge {

struct BlockInfo;
struct Block;

class block_index_not_found : public std::exception {
public:
    const char *what() const noexcept override {
        return "CBlockIndex not found";
    }
};

void log_print(const rust::Str logging_function, const rust::Str source_file,
               const uint32_t source_line, const rust::Str msg);

void log_print_chronik(const rust::Str logging_function,
                       const rust::Str source_file, const uint32_t source_line,
                       const rust::Str msg);

/**
 * Bridge to bitcoind to access the node.
 */
class ChronikBridge {
    const node::NodeContext &m_node;

public:
    ChronikBridge(const node::NodeContext &node) : m_node(node) {}

    BlockInfo get_chain_tip() const;

    const CBlockIndex &lookup_block_index(std::array<uint8_t, 32> hash) const;
};

std::unique_ptr<ChronikBridge> make_bridge(const node::NodeContext &node);

Block bridge_block(const CBlock &block, const CBlockIndex &bindex);

bool init_error(const rust::Str msg);

void abort_node(const rust::Str msg, const rust::Str user_msg);

} // namespace chronik_bridge

#endif // BITCOIN_CHRONIK_CPP_CHRONIK_BRIDGE_H
