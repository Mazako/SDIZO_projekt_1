project(tests)
add_subdirectory(googletest-1.13.0)

add_executable(test_run DynamicArrayTests.cpp DoubleLinkedListTest.cpp MaxHeapTest.cpp)
target_link_libraries(test_run SDIZO_PROJ_1)
target_link_libraries(test_run gtest gtest_main)