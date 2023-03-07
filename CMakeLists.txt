cmake_minimum_required(VERSION 3.24)
project(SDIZO_PROJ_1)

set(CMAKE_CXX_STANDARD 17)
include_directories(dynamic_array)
add_executable(SDIZO_PROJ_1 main.cpp dynamic_array/DynamicArray.cpp double_linked_list/node/Node.cpp double_linked_list/node/Node.h double_linked_list/DoubleLinkedList.cpp double_linked_list/DoubleLinkedList.h heap/MaxHeap.cpp heap/MaxHeap.h)

