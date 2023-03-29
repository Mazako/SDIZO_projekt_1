#ifndef MAIN_DATASTRUCTURESTESTER_H
#define MAIN_DATASTRUCTURESTESTER_H
#include <vector>
#include "dynamic_array/DynamicArray.h"
#include "double_linked_list/DoubleLinkedList.h"
#include "heap/MaxHeap.h"
#include "binary_search_tree/BinarySearchTree.h"
#include "red_black_tree/RedBlackTree.h"

class DataStructuresTester {
    DynamicArray dynamicArray;
    DoubleLinkedList doubleLinkedList;
    MaxHeap heap;
    BinarySearchTree binarySearchTree;
    RedBlackTree redBlackTree;
    static const std::vector<int> ARRAY_AND_LIST_TEST_RANGES;
public:
    //TESTS FOR DYNAMIC ARRAY
    void dynamicArrayStartInsertionTest(int count);

    void dynamicArrayMiddleInsertionTest(int count);

    void dynamicArrayEndInsertionTest(int count);

    void dynamicArrayStartDeletionTest(int count);

    void dynamicArrayMiddleDeletionTest(int count);

    void dynamicArrayEndDeletionTest(int count);

    void dynamicArrayAllTests(int count);

    //TESTS FOR DOUBLE LINKED LIST
    void doubleLinkedListStartInsertionTest(int count);

    void doubleLinkedListMiddleInsertionTest(int count);

    void doubleLinkedListEndInsertionTest(int count);

    void doubleLinkedListStartDeletionTest(int count);

    void doubleLinkedListMiddleDeletionTest(int count);

    void doubleLinkedListEndDeletionTest(int count);

    void doubleLinkedListAllTests(int count);
};


#endif //MAIN_DATASTRUCTURESTESTER_H
