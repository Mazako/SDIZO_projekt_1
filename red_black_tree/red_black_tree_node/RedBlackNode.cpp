//
// Created by micha on 21.03.2023.
//

#include "RedBlackNode.h"
#include <iostream>
RedBlackNode::RedBlackNode(int data, char color) {
    this->key = data;
    if (color != 'r' && color != 'b' && color != '\0') {
        throw std::invalid_argument("Invalid color of node");
    }
    this->color = color;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;

}

RedBlackNode::RedBlackNode(int data) {
    this->key = data;
    this->color = '\0';
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

RedBlackNode::RedBlackNode() {

}
