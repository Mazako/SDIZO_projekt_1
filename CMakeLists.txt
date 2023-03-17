cmake_minimum_required(VERSION 3.24)
project(SDIZO_PROJ_1)

set(CMAKE_CXX_STANDARD 17)
add_executable(SDIZO_PROJ_1 main.cpp dynamic_array/DynamicArray.cpp double_linked_list/node/Node.cpp double_linked_list/node/Node.h double_linked_list/DoubleLinkedList.cpp double_linked_list/DoubleLinkedList.h heap/MaxHeap.cpp heap/MaxHeap.h binary_search_tree/bst_node/BstNode.cpp binary_search_tree/bst_node/BstNode.h binary_search_tree/BinarySearchTree.cpp binary_search_tree/BinarySearchTree.h binary_search_tree/BinarySearchTree.h random/Random.cpp random/Random.h)

