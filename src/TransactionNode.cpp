#include <iostream>
#include "../includes/TransactionNode.hpp"

TransactionNode::TransactionNode(const std::string& data): transactionData(data), nextNode(nullptr){};