//
// Created by micha on 21.03.2023.
//

#ifndef SDIZO_PROJ_1_REDBLACKNODE_H
#define SDIZO_PROJ_1_REDBLACKNODE_H


class RedBlackNode {
public:
    RedBlackNode();

    RedBlackNode* left;
    RedBlackNode* right;
    RedBlackNode* parent;
    char color;
    int key;

    RedBlackNode(int data, char color);
    RedBlackNode(int data);
};


#endif //SDIZO_PROJ_1_REDBLACKNODE_H
