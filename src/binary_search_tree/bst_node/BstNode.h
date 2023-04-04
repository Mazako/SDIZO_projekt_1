#ifndef SDIZO_PROJ_1_BSTNODE_H
#define SDIZO_PROJ_1_BSTNODE_H


class BstNode {
public:
    int data;
    BstNode *left;
    BstNode *right;
    BstNode *parent;

    BstNode();
    BstNode(int data);
    ~BstNode();
};


#endif //SDIZO_PROJ_1_BSTNODE_H
