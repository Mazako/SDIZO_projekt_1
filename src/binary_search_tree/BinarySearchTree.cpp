#include <iostream>
#include <cmath>
#include <iomanip>
#include <queue>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    this->head = nullptr;
    this->size = 0;
}

void BinarySearchTree::insertNode(int data) {
    BstNode *newNode = new BstNode(data);
    BstNode *headPtr = head;
    BstNode *parentPtr = nullptr;
    while (headPtr != nullptr) {
        parentPtr = headPtr;
        if (data > headPtr->data) {
            headPtr = headPtr->right;
        } else if (data < headPtr ->data){
            headPtr = headPtr->left;
        } else {
            throw std::invalid_argument("Node already exists");
        }
    }

    newNode->parent = parentPtr;
    if (parentPtr == nullptr) {
        this->head = newNode;
    }
    else if (data > parentPtr->data) {
        parentPtr->right = newNode;
    } else {
        parentPtr->left = newNode;
    }
    size++;
}

void BinarySearchTree::deleteNode(int data) {
    BstNode *nodeToDelete = findNode(data);
    if (nodeToDelete == nullptr) {
        throw std::invalid_argument("Key does not exist");
    }
    if (nodeToDelete->left == nullptr) {
        transplant(nodeToDelete, nodeToDelete->right);
    } else if (nodeToDelete->right == nullptr) {
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
    }
    nodeToDelete->left = nullptr;
    nodeToDelete->right = nullptr;
    delete nodeToDelete;
    size--;
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
    while (nodePtr != nullptr) {
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
    printTreeRecursively(this->head, 0);
}

int BinarySearchTree::treeDepth(BstNode *root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + std::max(treeDepth(root->left), treeDepth(root->right));
}

BinarySearchTree::~BinarySearchTree() {
    delete this->head;
    this->head = nullptr;
}

void BinarySearchTree::deleteRec(BstNode *node) {
    if (node != nullptr) {
        node->parent = nullptr;
        deleteRec(node->left);
        deleteRec(node->right);
        delete node;
    }
}

void BinarySearchTree::printTreeRecursively(BstNode* node, int s) {
    if (node == nullptr) {
        return;
    }
    s += 10;
    printTreeRecursively(node->right, s);
    std::cout << std::endl;
    for (int i = 10; i < s; i++) {
        std::cout << " ";
    }
    std::cout << node->data << "\n";
    printTreeRecursively(node->left, s);

}
