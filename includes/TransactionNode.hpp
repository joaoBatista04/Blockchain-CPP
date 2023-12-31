#ifndef TRANSACTION_NODE_H
#define TRANSACTION_NODE_H

#include <string>

using namespace std;

class TransactionNode{
    public:
        std::string transactionData;
        TransactionNode* nextNode;
        
        TransactionNode(const std::string& data);
};

#endif