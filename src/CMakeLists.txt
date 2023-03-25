cmake_minimum_required(VERSION 3.24)
project(SDIZO_PROJ_1)

set(CMAKE_CXX_STANDARD 17)
add_library(SDIZO_PROJ_1  dynamic_array/DynamicArray.cpp double_linked_list/node/Node.cpp double_linked_list/node/Node.h double_linked_list/DoubleLinkedList.cpp double_linked_list/DoubleLinkedList.h heap/MaxHeap.cpp heap/MaxHeap.h binary_search_tree/bst_node/BstNode.cpp binary_search_tree/bst_node/BstNode.h binary_search_tree/BinarySearchTree.cpp binary_search_tree/BinarySearchTree.h binary_search_tree/BinarySearchTree.h random/Random.cpp random/Random.h red_black_tree/red_black_tree_node/RedBlackNode.cpp red_black_tree/red_black_tree_node/RedBlackNode.h red_black_tree/RedBlackTree.cpp red_black_tree/RedBlackTree.h dynamic_array/client/DynamicArrayClient.cpp dynamic_array/client/DynamicArrayClient.h)