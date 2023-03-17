
#ifndef SDIZO_PROJ_1_BINARYSEARCHTREE_H
#define SDIZO_PROJ_1_BINARYSEARCHTREE_H


#include "bst_node/BstNode.h"

class BinarySearchTree {
public:

    BstNode *head;

    BinarySearchTree();

    ~BinarySearchTree();

    void insertNode(int data);

    void deleteNode(int data);

    void printInorder();

    void printTree(int ident = 0, int h = 10);
private:
    BstNode *deleteNodeRecursively(BstNode *root, int data);

    BstNode *findMax(BstNode *head);

    BstNode *findMin(BstNode *head);

    void printInorderRecursively(BstNode *node);

    void printTreeRecursively(BstNode* root, int indent, int height);
};


#endif //SDIZO_PROJ_1_BINARYSEARCHTREE_H
