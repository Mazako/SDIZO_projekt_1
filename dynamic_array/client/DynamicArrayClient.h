//
// Created by micha on 25.03.2023.
//

#ifndef SDIZO_PROJ_1_DYNAMICARRAYCLIENT_H
#define SDIZO_PROJ_1_DYNAMICARRAYCLIENT_H


#include "../DynamicArray.h"

class DynamicArrayClient {
    DynamicArray *array = new DynamicArray();

    void printArray();

    void printMenu();

    void add();

    void addAtIndex();

    void remove();

    void readFromFile();

    void printPlaceholder();
public:

    DynamicArrayClient();

    ~DynamicArrayClient();

    void startMainLoop();
};


#endif //SDIZO_PROJ_1_DYNAMICARRAYCLIENT_H
