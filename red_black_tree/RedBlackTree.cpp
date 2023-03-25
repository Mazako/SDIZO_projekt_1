//
// Created by micha on 21.03.2023.
//
#include <iostream>
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    this->nullNode = new RedBlackNode(0, 'b');
    this->root = new RedBlackNode();
    this->root->parent = this->nullNode;

}

void RedBlackTree::leftRotate(RedBlackNode *node) {
    RedBlackNode *pivot = node->right;
    node->right = pivot->left;
    if (pivot->left != this->nullNode)
        pivot->left->parent = node;
    pivot->parent = node->parent;
    if (node->parent == this->nullNode)
        this->root = pivot;
    else if (node == node->parent->left)
        node->parent->left = pivot;
    else
        node->parent->right = pivot;
    pivot->left = node;
    node->parent = pivot;

}

void RedBlackTree::rightRotate(RedBlackNode *node) {
    RedBlackNode *pivot = node->left;
    node->left = pivot->right;
    if (pivot->right != this->nullNode)
        pivot->right->parent = node;
    pivot->parent = node->parent;
    if (node->parent == this->nullNode)
        this->root = pivot;
    else if (node->parent->left == node) {
        node->parent->left = pivot;
    } else {
        node->parent->right = node;
    }
    pivot->right = node;
    node->parent = pivot;
}

void RedBlackTree::insert(int key) {
    RedBlackNode *newNode = new RedBlackNode(key, 'r');
    RedBlackNode *nodePtr = this->root;
    RedBlackNode *parent = nullptr;
    while (nodePtr != this->nullNode) {
        parent = nodePtr;
        if (key > nodePtr->key) {
            nodePtr = nodePtr->right;
        } else {
            nodePtr = nodePtr->left;
        }
    }
    newNode->parent = parent;
    newNode->left = this->nullNode;
    newNode->right = this->nullNode;
    if (key > parent->key) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
    insertFixup(newNode);
}

void RedBlackTree::insertFixup(RedBlackNode *node) {
    while (node->parent->color == 'r') {
        if (node->parent == node->parent->parent->left) {
            RedBlackNode *uncle = node->parent->parent->right;
            if (uncle->color == 'r') {
                node->parent->color = 'b';
                uncle->color = 'b';
                node->parent->parent->color = 'r';
                node = node->parent->parent;
            } else {
                if (node->parent->right == node) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = 'b';
                node->parent->parent->color = 'r';
                rightRotate(node->parent->parent);
            }
        } else {
            RedBlackNode *uncle = node->parent->parent->left;
            if (uncle->color == 'r') {
                node->parent->color = 'b';
                uncle->color = 'b';
                node->parent->parent->color = 'r';
                node = node->parent->parent;
            } else {
                if (node->parent->right == node) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = 'b';
                node->parent->parent->color = 'r';
                rightRotate(node->parent->parent);
            }
        }
    }
    this->root->color = 'b';
}

void RedBlackTree::redBlackTransplant(RedBlackNode *node, RedBlackNode *child) {
    if (node->parent == this->nullNode) {
        this->root = child;
    } else if (node == node->parent->left) {
        node->parent->left = child;
    } else {
        node->parent->right = child;
    }
    child->parent = node->parent;

}

void RedBlackTree::deleteNode(int key) {
    RedBlackNode *nodeToDelete = findNode(key);
    if (nodeToDelete == nullptr) {
        throw std::invalid_argument("Key doesn't exist");
    }
    RedBlackNode *originalNode = nodeToDelete;
    RedBlackNode *x;
    char originalColor = originalNode->color;
    if (nodeToDelete->left == this->nullNode) {
        x = nodeToDelete->right;
        redBlackTransplant(nodeToDelete, nodeToDelete->right);
    } else if (nodeToDelete->left != this->nullNode) {
        x = nodeToDelete->left;
        redBlackTransplant(nodeToDelete, nodeToDelete->left);
    } else {
        originalNode = findMin(nodeToDelete->right);
        x = originalNode->right;
        originalColor = originalNode->color;
        if (nodeToDelete == originalNode->parent) {
            x->parent = originalNode;
        } else {
            redBlackTransplant(originalNode, originalNode->right);
            originalNode->right = nodeToDelete->right;
            originalNode->right->parent = originalNode->right;
        }
        redBlackTransplant(nodeToDelete, originalNode);
        originalNode->left = nodeToDelete->left;
        originalNode->left->parent = originalNode->left;
        originalNode->color = nodeToDelete->color;
    }
    if (originalColor == 'b') {
        deleteFixup(x);
    }
    delete nodeToDelete;

}

RedBlackNode *RedBlackTree::findMin(RedBlackNode *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

RedBlackNode *RedBlackTree::findNode(int key) {
    RedBlackNode *nodePtr = this->root;
    while (nodePtr != nullptr) {
        if (key > nodePtr->key) {
            nodePtr = nodePtr->right;
        } else if (key < nodePtr->key) {
            nodePtr = nodePtr->left;
        } else {
            return nodePtr;
        }
    }
    return nullptr;
}

void RedBlackTree::deleteFixup(RedBlackNode *node) {
    while (node != this->root && node->color == 'b') {
        if (node == node->parent->left) {
            RedBlackNode *sibling = node->parent->left;
            if (sibling->color == 'r') {
                sibling->color = 'b';
                node->parent->color = 'r';
                leftRotate(node->parent);
                sibling = node->parent->right;
            }
            if (sibling->left->color == 'b' && sibling->right->color == 'b') {
                sibling->color = 'r';
                node = node->parent;
            } else {
                if (sibling->right->color == 'b') {
                    sibling->left->color = 'b';
                    sibling->color = 'r';
                    rightRotate(sibling);
                    sibling = node->parent->right;
                }
                sibling->color = node->parent->color;
                node->parent->color = 'b';
                sibling->right->color = 'b';
                leftRotate(node->parent);
                node = this->root;
            }
        } else {
            RedBlackNode *sibling = node->parent->right;
            if (sibling->color == 'r') {
                sibling->color = 'b';
                node->parent->color = 'r';
                leftRotate(node->parent);
                sibling = node->parent->left;
            }
            if (sibling->left->color == 'b' && sibling->right->color == 'b') {
                sibling->color = 'r';
                node = node->parent;
            } else {
                if (sibling->left->color == 'b') {
                    sibling->right->color = 'b';
                    sibling->color = 'r';
                    rightRotate(sibling);
                    sibling = node->parent->left;
                }
                sibling->color = node->parent->color;
                node->parent->color = 'b';
                sibling->left->color = 'b';
                leftRotate(node->parent);
                node = this->root;
            }
        }
    }
    node->color = 'b';
}