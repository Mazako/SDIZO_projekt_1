#ifndef MAIN_RBTREECLIENT_H
#define MAIN_RBTREECLIENT_H
#include "red_black_tree/RedBlackTree.h"
class RbTreeClient {
    RedBlackTree* tree;

    void printTree();

    void printPlaceholder();

    void printMenu();

    void insertNode();

    void deleteNode();

    void readTreeFromFile();


public:
    void startMainLoop();

    RbTreeClient();

    ~RbTreeClient();

};


#endif //MAIN_RBTREECLIENT_H
