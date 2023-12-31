#include <iostream>
#include <openssl/sha.h>
#include "../includes/MerkleNode.hpp"

MerkleNode::MerkleNode(const std::string& data): __data(data), __hash(calculateHash(data)){};

std::string MerkleNode::getData() const{
    return __data;
}

std::string MerkleNode::getHash() const{
    return __hash;
}

std::string MerkleNode::calculateHash(const std::string& data) const{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.length());
    SHA256_Final(hash, &sha256);

    std::string hashStr;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i){
        hashStr += hash[i];
    }

    return hashStr;
}