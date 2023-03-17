//
// Created by micha on 07.03.2023.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    this->head = nullptr;
}

void BinarySearchTree::insertNode(int data) {
    BstNode *newNode = new BstNode(data);
    if (this->head == nullptr) {
        this->head = newNode;
        return;
    }
    BstNode *headPtr = head;
    BstNode *parentPtr = nullptr;
    while (headPtr != nullptr) {
        parentPtr = headPtr;
        if (data > headPtr->data) {
            headPtr = headPtr->right;
        } else {
            headPtr = headPtr->left;
        }
    }

    newNode->parent = parentPtr;
    if (data > parentPtr->data) {
        parentPtr->right = newNode;
    } else {
        parentPtr->left = newNode;
    }
}

void BinarySearchTree::deleteNode(int data) { this->head = deleteNodeRecursively(this->head, data); }

BstNode *BinarySearchTree::deleteNodeRecursively(BstNode *root, int data) {
    if (root == nullptr) {
        return root;
    }
    if (data > root->data) {
        root->right = deleteNodeRecursively(root->right, data);
    } else if (data < root->data) {
        root->left = deleteNodeRecursively(root->left, data);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            BstNode *tmp = root->right;
            tmp->parent = root->parent;
            root = nullptr;
            delete root;
            return tmp;
        } else if (root->right == nullptr) {
            BstNode *tmp = root->left;
            tmp->parent = root->parent;
            root = nullptr;
            delete root;
            return tmp;
        } else {
            BstNode* minNode = findMin(root->right);
            root->data = minNode->data;
            root->right = deleteNodeRecursively(root->right, minNode->data);
        }
        return root;
    }
}

BstNode *BinarySearchTree::findMax(BstNode *head) {
    while (head->right != nullptr) {
        head = head->right;
    }
    return head;
}

BstNode *BinarySearchTree::findMin(BstNode *head) {
    while (head->left != nullptr) {
        head = head->left;
    }
    return head;
}

void BinarySearchTree::printInorder() {
    printInorderRecursively(this->head);
    std::cout << std::endl;
}

void BinarySearchTree::printInorderRecursively(BstNode *node) {
    if (node != nullptr) {
        printInorderRecursively(node->left);
        std::cout << node->data << " ";
        printInorderRecursively(node->right);
    }


}

void BinarySearchTree::printTreeRecursively(BstNode *root, int space, int height) {
    if (root == nullptr) {
        return;
    }

    space += height;

    printTreeRecursively(root->right, space, height);

    std::cout << std::endl;
    for (int i = height; i < space; i++) {
        std::cout << " ";
    }
    std::cout << root->data << std::endl;

    printTreeRecursively(root->left, space, height);
}

void BinarySearchTree::printTree(int indent, int h) { printTreeRecursively(this->head, indent, h);}
