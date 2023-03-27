//
// Created by micha on 21.03.2023.
//

#ifndef SDIZO_PROJ_1_REDBLACKTREE_H
#define SDIZO_PROJ_1_REDBLACKTREE_H


#include "red_black_tree_node/RedBlackNode.h"

class RedBlackTree {
    RedBlackNode *nullNode;
public:
    RedBlackNode *root;

    RedBlackTree();

    void leftRotate(RedBlackNode *node);

    void rightRotate(RedBlackNode *node);

    void insert(int key);

    void deleteNode(int key);

    RedBlackNode *findNode(int key);

    RedBlackNode *findMin(RedBlackNode *node);

    RedBlackNode *findMax(RedBlackNode *node);

    void printTreeDiagram();

    int treeDepth(RedBlackNode *root);


private:
    void redBlackTransplant(RedBlackNode *node, RedBlackNode *child);

    void deleteFixup(RedBlackNode *node);

    void insertFixup(RedBlackNode *node);

    void printTreeRecursively(RedBlackNode *node, int s);

};


#endif //SDIZO_PROJ_1_REDBLACKTREE_H
