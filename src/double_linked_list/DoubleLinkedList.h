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

    int get(int index);

    int removeAt(int index);

    void addAt(int index, int data);

    void printList();

    void printReversed();
};


#endif //SDIZO_PROJ_1_DOUBLELINKEDLIST_H
