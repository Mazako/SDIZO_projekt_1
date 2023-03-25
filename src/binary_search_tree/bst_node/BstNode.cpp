#include <iostream>
#include "BstNode.h"

BstNode::BstNode() {
    this->data = 0;
    this->right = nullptr;
    this->left = nullptr;
    this->parent = nullptr;
}

BstNode::BstNode(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}
