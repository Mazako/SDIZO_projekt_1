#ifndef SDIZO_PROJ_1_DOUBLELINKEDLIST_H
#define SDIZO_PROJ_1_DOUBLELINKEDLIST_H

#include "node/Node.h"

class DoubleLinkedList {
    Node *head = nullptr;
    int size = 0;
public:
    ~DoubleLinkedList();

    void push(int data);

    int pop();

    void unshift(int data);

    int shift();

    int removeAt(int index);

    int addAt(int index);

    void printList();

    void printReversed();
};


#endif //SDIZO_PROJ_1_DOUBLELINKEDLIST_H
