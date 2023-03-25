
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

    BstNode *findNode(int data);

    void printTreeDiagram();
private:
    void transplant(BstNode *nodeToBeReplaced, BstNode* child);

    BstNode *findMax(BstNode *head);

    BstNode *findMin(BstNode *head);

    void printInorderRecursively(BstNode *node);

    int treeDepth(BstNode *root);
};


#endif //SDIZO_PROJ_1_BINARYSEARCHTREE_H
