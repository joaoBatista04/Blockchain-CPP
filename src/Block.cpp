#include <iostream>
#include <openssl/sha.h>
#include "../includes/Block.hpp"
#include "../includes/MerkleTree.hpp"


Block::Block(int idx, const std::string& timestamp, TransactionNode* transactions, const std::string& previousHash): index(idx), timestamp(timestamp), transactionListHead(transactions), previousHash(previousHash){
    std::vector<std::string> transactionData = extractTransactionData();
    
    MerkleTree merkleTree(transactionData);
    merkleRootHash = merkleTree.getRootHash();
        
    this->blockHash = calculateBlockHash();
}
    
vector<std::string> Block::extractTransactionData() const{
    std::vector<std::string> transactionData;
    TransactionNode* current = transactionListHead;
    
    while(current){
        transactionData.push_back(current->transactionData);
        current = current->nextNode;
    }

    return transactionData;
}

std::string Block::calculateBlockHash() const{
    std::string blockData = std::to_string(index) + timestamp + previousHash + merkleRootHash;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, blockData.c_str(), blockData.length());
    SHA256_Final(hash, &sha256);

    std::string calculatedHash;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i){
        calculatedHash += hash[i];
    }

    return calculatedHash;
}