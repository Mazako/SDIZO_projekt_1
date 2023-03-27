//
// Created by micha on 27.03.2023.
//

#ifndef MAIN_BSTCLIENT_H
#define MAIN_BSTCLIENT_H

#include "binary_search_tree/BinarySearchTree.h"

class BstClient {
    BinarySearchTree *bst;

    void printTree();

    void printPlaceholder();

    void printMenu();

    void insertNode();

    void deleteNode();

    void readTreeFromFile();


public:
    void startMainLoop();

    BstClient();

    ~BstClient();

};


#endif //MAIN_BSTCLIENT_H
