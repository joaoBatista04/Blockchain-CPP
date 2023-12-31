#ifndef MERKLENODE_H
#define MERKLENODE_H

#include <string>

using namespace std;

class MerkleNode{
    public:
        std::string __data;
        std::string __hash;

        MerkleNode(const std::string& data);

        std::string getData() const;
        std::string getHash() const;

    private:
        std::string calculateHash(const std::string& data) const;
};

#endif