#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "./TransactionNode.hpp"

class Block{
    private:
        int index;
        std::string timestamp;
        TransactionNode* transactionListHead;
        std::string previousHash;

    public:
        std::string blockHash;
        std::string merkleRootHash;

        Block(int idx, const std::string& timestamp, TransactionNode* transactions, const std::string& previousHash);
        vector<std::string> extractTransactionData() const;
        std::string calculateBlockHash() const;
        
};

#endif