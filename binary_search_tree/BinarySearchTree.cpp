//
// Created by micha on 07.03.2023.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <queue>
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

void BinarySearchTree::deleteNode(int data) {
    BstNode *nodeToDelete = findNode(data);
    if (nodeToDelete == nullptr) {
        throw std::invalid_argument("Key does not exist");
    }
    if (nodeToDelete->left == nullptr) {
        transplant(nodeToDelete, nodeToDelete->right);
    } else if (nodeToDelete->left != nullptr) {
        transplant(nodeToDelete, nodeToDelete->left);
    } else {
        BstNode *successor = findMin(nodeToDelete->right);
        if (nodeToDelete->right != successor) {
            transplant(successor, successor->right);
            successor->right = nodeToDelete->right;
            successor->right->parent = nodeToDelete;
        }
        transplant(nodeToDelete, successor);
        successor->left = nodeToDelete->left;
        successor->left->parent = successor;
        delete nodeToDelete;
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

void BinarySearchTree::transplant(BstNode *nodeToBeReplaced, BstNode *child) {
    if (nodeToBeReplaced->parent == nullptr) {
        this->head = child;
    } else if (nodeToBeReplaced->parent->left == nodeToBeReplaced) {
        nodeToBeReplaced->parent->left = child;
    } else {
        nodeToBeReplaced->parent->right = child;
    }
    if (child != nullptr) {
        child->parent = nodeToBeReplaced->parent;
    }

}

BstNode *BinarySearchTree::findNode(int data) {
    BstNode *nodePtr = this->head;
    while (this->head != nullptr) {
        if (data > nodePtr->data) {
            nodePtr = nodePtr->right;
        } else if (data < nodePtr->data) {
            nodePtr = nodePtr->left;
        } else {
            return nodePtr;
        }
    }
    return nullptr;
}


void BinarySearchTree::printTreeDiagram() {
    BstNode *root = this->head;
    if (root == nullptr) {
        std::cout << "The tree is empty." << std::endl;
        return;
    }
    std::queue<BstNode *> q;
    q.push(root);
    int depth = treeDepth(root);
    int level = 1;
    while (!q.empty()) {
        int nodeCount = q.size();
        int space = std::pow(2, depth - level + 1) - 1;
        while (nodeCount > 0) {
            BstNode *node = q.front();
            q.pop();

            for (int i = 0; i < space; i++) {
                std::cout << " ";
            }
            if (node == nullptr) {
                std::cout << " ";
                q.push(nullptr);
                q.push(nullptr);
            } else {
                std::cout << node->data;
                q.push(node->left);
                q.push(node->right);
            }
            for (int i = 0; i < space; i++) {
                std::cout << " ";
            }
            nodeCount--;
        }
        std::cout << std::endl;
        level++;
        bool isEnd = true;
        std::queue<BstNode *> tempQueue = q;
        while (!tempQueue.empty()) {
            if (tempQueue.front() != nullptr) {
                isEnd = false;
                break;
            }
            tempQueue.pop();
        }
        if (isEnd) {
            break;
        }
    }
}

int BinarySearchTree::treeDepth(BstNode *root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + std::max(treeDepth(root->left), treeDepth(root->right));
}