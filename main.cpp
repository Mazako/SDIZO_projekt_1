#include <iostream>
#include "dynamic_array/DynamicArray.h"
#include "double_linked_list/DoubleLinkedList.h"
#include "heap/MaxHeap.h"
void simpleDynamicArrayTest();

void simpleDoubleLinkedListTest();

void simpleMaxHeapTest();

using namespace std;

int main() {
    simpleMaxHeapTest();
}

void simpleDoubleLinkedListTest() {
    auto *list = new DoubleLinkedList();
    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);
    list->addAt(5, 5);
//    list->removeAt(4);
    list->printList();
    list->printReversed();

    delete list;
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

void simpleMaxHeapTest() {
    int a[] = {1, 32, 2, 12, 93, 4};
    auto* heap = new MaxHeap(a, 6);
    heap->printHeap();
//    delete heap;
}
