//
// Created by micha on 21.03.2023.
//

#ifndef SDIZO_PROJ_1_REDBLACKTREE_H
#define SDIZO_PROJ_1_REDBLACKTREE_H


#include "red_black_tree_node/RedBlackNode.h"

class RedBlackTree {
    RedBlackNode *nullNode;
    RedBlackNode *root;
public:
    RedBlackTree();

    void leftRotate(RedBlackNode *node);

    void rightRotate(RedBlackNode *node);

    void insert(int key);

    void deleteNode(int key);

    RedBlackNode *findNode(int key);

    static RedBlackNode *findMin(RedBlackNode *node);

private:
    void redBlackTransplant(RedBlackNode *node, RedBlackNode* child);

    void deleteFixup(RedBlackNode *node);

    void insertFixup(RedBlackNode *node);

};


#endif //SDIZO_PROJ_1_REDBLACKTREE_H
