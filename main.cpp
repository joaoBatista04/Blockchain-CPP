#include <iostream>
#include <string>
#include <sstream>
#include "./includes/Block.hpp"
#include "./includes/TransactionNode.hpp"

std::string hexToDecimal(const std::string& hex) {
    try {
        unsigned long long decimalValue = std::stoull(hex, 0, 16);
        return std::to_string(decimalValue);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro: A string hexadecimal não é válida." << std::endl;
        return "Erro na conversão";
    }
}

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