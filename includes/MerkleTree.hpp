#ifndef MERKLETREE_H
#define MERKLETREE_H

#include <string>
#include <vector>
#include "./MerkleNode.hpp"

using namespace std;

class MerkleTree{
    public:
        MerkleTree(const std::vector<std::string>& data);
        std::string getRootHash() const;

    private:
        std::vector<MerkleNode> __nodes;
        void buildTree();
};

#endif