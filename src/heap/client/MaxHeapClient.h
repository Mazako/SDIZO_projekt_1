//
// Created by micha on 27.03.2023.
//

#ifndef MAIN_MAXHEAPCLIENT_H
#define MAIN_MAXHEAPCLIENT_H
#include "heap/MaxHeap.h"

class MaxHeapClient {
    MaxHeap* heap;

    void printPlaceholder();

    void printMenu();

    void printHeap();

    void addToHeap();

    void removeMaxFromHeap();

    void readHeapFromFile();

public:
    void startMainLoop();

    MaxHeapClient();

    ~MaxHeapClient();
};


#endif //MAIN_MAXHEAPCLIENT_H
