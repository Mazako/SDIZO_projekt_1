cmake_minimum_required(VERSION 3.24)
project(SDIZO_PROJ_1)

set(CMAKE_CXX_STANDARD 17)
add_library(SDIZO_PROJ_1
        dynamic_array/DynamicArray.cpp
        double_linked_list/node/Node.cpp
        double_linked_list/node/Node.h
        double_linked_list/DoubleLinkedList.cpp
        double_linked_list/DoubleLinkedList.h
        heap/MaxHeap.cpp
        heap/MaxHeap.h
        binary_search_tree/bst_node/BstNode.cpp
        binary_search_tree/bst_node/BstNode.h
        binary_search_tree/BinarySearchTree.cpp
        binary_search_tree/BinarySearchTree.h
        red_black_tree/red_black_tree_node/RedBlackNode.cpp
        red_black_tree/red_black_tree_node/RedBlackNode.h
        red_black_tree/RedBlackTree.cpp
        red_black_tree/RedBlackTree.h
        dynamic_array/client/DynamicArrayClient.cpp
        dynamic_array/client/DynamicArrayClient.h
        utils/Utils.h
        utils/Utils.cpp
        double_linked_list/client/DoubleLinkedListClient.h
        double_linked_list/client/DoubleLinkedListClient.cpp
        heap/client/MaxHeapClient.h
        heap/client/MaxHeapClient.cpp
        binary_search_tree/client/BstClient.h
        binary_search_tree/client/BstClient.cpp
        red_black_tree/client/RbTreeClient.h
        red_black_tree/client/RbTreeClient.cpp
        test_performer/DataStructuresTester.h test_performer/DataStructuresTester.cpp)