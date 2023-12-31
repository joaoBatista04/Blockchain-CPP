#include <iostream>
#include <string>
#include <sstream>
#include "./includes/Block.hpp"
#include "./includes/TransactionNode.hpp"

int main(){
    TransactionNode* transactionListHead = new TransactionNode("Transaction 1");
    transactionListHead->nextNode = new TransactionNode("Transaction 2");
    transactionListHead->nextNode->nextNode = new TransactionNode("Transaction 3");

    Block block(1, "2023-01-01 12:00:00", transactionListHead, "PreviousHash");

    std::cout << "Block Hash: " << block.blockHash << std::endl;
    std::cout << "Merkle Root Hash: " << block.merkleRootHash << std::endl;

    while (transactionListHead) {
        TransactionNode* temp = transactionListHead;
        transactionListHead = transactionListHead->nextNode;
        delete temp;
    }

    return 0;
}