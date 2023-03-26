#ifndef MAIN_DOUBLELINKEDLISTCLIENT_H
#define MAIN_DOUBLELINKEDLISTCLIENT_H
#include "double_linked_list/DoubleLinkedList.h"

class DoubleLinkedListClient {
    DoubleLinkedList *list;

    void printMenu();

    void printPlaceholder();

    void printList();

    void addAtStart();

    void addAtEnd();

    void removeFromStart();

    void removeFromEnd();

    void addAnywhere();

    void removeAnywhere();

    void readFromFile();


public:
    void startMainLoop();

    DoubleLinkedListClient();

    ~DoubleLinkedListClient();
};


#endif //MAIN_DOUBLELINKEDLISTCLIENT_H
