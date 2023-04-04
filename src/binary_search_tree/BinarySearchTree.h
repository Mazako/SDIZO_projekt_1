
#ifndef SDIZO_PROJ_1_BINARYSEARCHTREE_H
#define SDIZO_PROJ_1_BINARYSEARCHTREE_H


#include "bst_node/BstNode.h"

class BinarySearchTree {
public:

    BstNode *head;
    int size;

    BinarySearchTree();

    ~BinarySearchTree();

    void insertNode(int data);

    void deleteNode(int data);

    void printInorder();

    BstNode *findNode(int data);

    void printTreeDiagram();

    int treeDepth(BstNode *root);

    BstNode *findMax(BstNode *head);

    BstNode *findMin(BstNode *head);


private:
    void transplant(BstNode *nodeToBeReplaced, BstNode* child);

    void printInorderRecursively(BstNode *node);

    void deleteRec(BstNode* node);

    void printTreeRecursively(BstNode* node, int s);

};


#endif //SDIZO_PROJ_1_BINARYSEARCHTREE_H
