#ifndef MAIN_DATASTRUCTURESTESTER_H
#define MAIN_DATASTRUCTURESTESTER_H

#include <vector>
#include "dynamic_array/DynamicArray.h"
#include "double_linked_list/DoubleLinkedList.h"
#include "heap/MaxHeap.h"
#include "binary_search_tree/BinarySearchTree.h"
#include "red_black_tree/RedBlackTree.h"

class DataStructuresTester {
//    DynamicArray *dynamicArray;
//    DoubleLinkedList *doubleLinkedList;
//    MaxHeap *heap;
//    BinarySearchTree *binarySearchTree;
//    RedBlackTree *redBlackTree;
    static const std::vector<int> RANGES;
    static const int TEST_REPEATS;
public:
    DataStructuresTester();

    ~DataStructuresTester();

    //TESTS FOR DYNAMIC ARRAY
    void dynamicArrayStartInsertionTest();

    void dynamicArrayMiddleInsertionTest();

    void dynamicArrayEndInsertionTest();

    void dynamicArrayStartDeletionTest();

    void dynamicArrayMiddleDeletionTest();

    void dynamicArrayEndDeletionTest();

    void dynamicArrayAllTests();

    //TESTS FOR DOUBLE LINKED LIST
    void doubleLinkedListStartInsertionTest();

    void doubleLinkedListMiddleInsertionTest();

    void doubleLinkedListEndInsertionTest();

    void doubleLinkedListStartDeletionTest();

    void doubleLinkedListMiddleDeletionTest();

    void doubleLinkedListEndDeletionTest();

    void doubleLinkedListAllTests();

    //HEAP TESTS
    void maxHeapInsertTest();

    void maxHeapDeleteTest();

    void maxHeapAllTests();

    // BINARY SEARCH TREE TEST
    void binarySearchTreeInsertionTest();

    void binarySearchTreeDeletionTest();

    void binarySearchTreeSearchingTest();

    void binarySearchTreeAllTests();

    // RED BLACK TREE TEST

    void redBlackTreeInsertionTest();

    void redBlackTreeDeletionTest();

    void redBlackTreeSearchingTest();

    void redBlackTreeAllTests();

};


#endif //MAIN_DATASTRUCTURESTESTER_H
