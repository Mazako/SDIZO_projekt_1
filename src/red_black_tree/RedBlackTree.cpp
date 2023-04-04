#include <iostream>
#include <queue>
#include <valarray>
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    this->nullNode = new RedBlackNode(0, 'b');
    this->root = nullNode;
    this->root->parent = nullNode;
    this->root->left = nullNode;
    this->root->right = nullNode;
    this->size = 0;

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
        node->parent->right = pivot;
    }
    pivot->right = node;
    node->parent = pivot;
}

void RedBlackTree::insert(int key) {
    RedBlackNode *newNode = new RedBlackNode(key, 'r');
    RedBlackNode *nodePtr = this->root;
    RedBlackNode *parent = this->nullNode;
    while (nodePtr != this->nullNode) {
        parent = nodePtr;
        if (key > nodePtr->key) {
            nodePtr = nodePtr->right;
        } else if (key < nodePtr->key){
            nodePtr = nodePtr->left;
        } else {
            throw std::invalid_argument("Node exists");
        }
    }
    newNode->parent = parent;
    if (parent == this->nullNode) {
        this->root = newNode;
    }
    else if (key > parent->key) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
    newNode->left = this->nullNode;
    newNode->right = this->nullNode;
    insertFixup(newNode);
    size++;
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
                if (node->parent->left == node) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = 'b';
                node->parent->parent->color = 'r';
                leftRotate(node->parent->parent);
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
    if (nodeToDelete == nullNode) {
        throw std::invalid_argument("Key doesn't exist");
    }
    RedBlackNode *originalNode = nodeToDelete;
    RedBlackNode *x;
    char originalColor = originalNode->color;
    if (nodeToDelete->left == this->nullNode) {
        x = nodeToDelete->right;
        redBlackTransplant(nodeToDelete, nodeToDelete->right);
    } else if (nodeToDelete->right == this->nullNode) {
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
            originalNode->right->parent = originalNode;
        }
        redBlackTransplant(nodeToDelete, originalNode);
        originalNode->left = nodeToDelete->left;
        originalNode->left->parent = originalNode;
        originalNode->color = nodeToDelete->color;
    }
    if (originalColor == 'b') {
        deleteFixup(x);
    }
    delete nodeToDelete;
    size--;

}

RedBlackNode *RedBlackTree::findMin(RedBlackNode *node) {
    while (node->left != nullNode) {
        node = node->left;
    }
    return node;
}

RedBlackNode *RedBlackTree::findNode(int key) {
    RedBlackNode *nodePtr = this->root;
    while (nodePtr != nullNode) {
        if (key > nodePtr->key) {
            nodePtr = nodePtr->right;
        } else if (key < nodePtr->key) {
            nodePtr = nodePtr->left;
        } else {
            return nodePtr;
        }
    }
    return nullNode;
}

void RedBlackTree::deleteFixup(RedBlackNode *node) {
    while (node != this->root && node->color == 'b') {
        if (node == node->parent->left) {
            RedBlackNode *sibling = node->parent->right;
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
            RedBlackNode *sibling = node->parent->left;
            if (sibling->color == 'r') {
                sibling->color = 'b';
                node->parent->color = 'r';
                rightRotate(node->parent);
                sibling = node->parent->left;
            }
            if (sibling->left->color == 'b' && sibling->right->color == 'b') {
                sibling->color = 'r';
                node = node->parent;
            } else {
                if (sibling->left->color == 'b') {
                    sibling->right->color = 'b';
                    sibling->color = 'r';
                    leftRotate(sibling);
                    sibling = node->parent->left;
                }
                sibling->color = node->parent->color;
                node->parent->color = 'b';
                sibling->left->color = 'b';
                rightRotate(node->parent);
                node = this->root;
            }
        }
    }
    node->color = 'b';
}

RedBlackNode *RedBlackTree::findMax(RedBlackNode *node) {
    while (node->right != nullNode) {
        node = node->right;
    }
    return node;
}

int RedBlackTree::treeDepth(RedBlackNode *root) {
    if (root == nullNode) {
        return 0;
    }
    return 1 + std::max(treeDepth(root->left), treeDepth(root->right));
}

void RedBlackTree::printTreeDiagram() {
    printTreeRecursively(this->root, 0);
}

void RedBlackTree::printTreeRecursively(RedBlackNode *node, int s) {
    if (node == this->nullNode) {
        return;
    }
    s += 10;
    printTreeRecursively(node->right, s);
    std::cout << std::endl;
    for (int i = 0; i < s; i++) {
        std::cout << " ";
    }
    std::cout << node->key << ":" << node->color << "\n";
    printTreeRecursively(node->left, s);
}

int RedBlackTree::sizeRecursively(RedBlackNode *node) {
    if (node == nullNode) {
        return 0;
    }
    return 1 + sizeRecursively(node->left) + sizeRecursively(node->right);
}

int RedBlackTree::getRealSize() {
    return sizeRecursively(this->root);
}

RedBlackTree::~RedBlackTree() {
    deleteRec(this->root);
    delete this->nullNode;
}

void RedBlackTree::deleteRec(RedBlackNode *node) {
    if (node != nullNode) {
        deleteRec(node ->left);
        deleteRec(node ->right);
        delete node;
    }
}

