#include <iostream>
#include "dynamic_array/DynamicArray.h"
#include "double_linked_list/DoubleLinkedList.h"
void simpleDynamicArrayTest();

void simpleDoubleLinkedListTest();

using namespace std;

int main() {
    simpleDoubleLinkedListTest();
}

void simpleDoubleLinkedListTest() {
    auto* list = new DoubleLinkedList();
    list->push(1);
    list->push(2);
    list->push(3);
    list->printList();
    list->printReversed();
    list->pop();
    list->printList();
    list->printReversed();
    list->pop();
    list->pop();
    list->printList();
    list->printReversed();
}

void simpleDynamicArrayTest() {
    auto *array = new DynamicArray();

    array->add(1);
    array->add(2);
    array->add(3);
    array->printArray();
    array->addAt(0, -1);
    array->addAt(2, 4);
    array->printArray();
    array->remove(0);
    array->remove(3);
    array->addAt(2, 100);
    array->printArray();

    delete array;
}
