#include <iostream>
#include "../includes/MerkleTree.hpp"


MerkleTree::MerkleTree(const std::vector<std::string>& data){
    for(const auto& item : data) {
        __nodes.emplace_back(item);
    }

    buildTree();
}

std::string MerkleTree::getRootHash() const{
    if (__nodes.empty()) {
        return "";
    }

    return __nodes[0].getHash();
}

void MerkleTree::buildTree(){
    if (__nodes.empty()) {
        return;
    }

    std::vector<MerkleNode> currentLevel = __nodes;

    while (currentLevel.size() > 1) {
        std::vector<MerkleNode> nextLevel;

        for (size_t i = 0; i < currentLevel.size(); i += 2) {
            MerkleNode left = currentLevel[i];
            MerkleNode right = (i + 1 < currentLevel.size()) ? currentLevel[i + 1] : currentLevel[i];
            std::string combinedData = left.getHash() + right.getHash();
            nextLevel.emplace_back(combinedData);
        }
        
        currentLevel = nextLevel;
    }
}