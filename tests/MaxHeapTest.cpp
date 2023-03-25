#include "gtest/gtest.h"
#include "heap/MaxHeap.h"

class MaxHeapTest : public ::testing::Test {

};

TEST_F(MaxHeapTest, EmptyHeap) {
    MaxHeap heap;
    ASSERT_THROW(heap.removeMax(), std::logic_error);
    ASSERT_EQ(heap.getSize(), 0);
}

TEST_F(MaxHeapTest, InsertAndRemoveMax) {
    MaxHeap heap;
    heap.insert(3);
    ASSERT_EQ(heap.getMax(), 3);
    heap.insert(5);
    ASSERT_EQ(heap.getMax(), 5);
    heap.insert(1);
    ASSERT_EQ(heap.getMax(), 5);
    ASSERT_EQ(heap.removeMax(), 5);
    ASSERT_EQ(heap.getMax(), 3);
}

TEST_F(MaxHeapTest, HeapifyArray) {
    int n = 7;
    int *inputArray = new int[n]{1, 2, 3, 4, 5, 6, 7};
    MaxHeap heap(inputArray, n);

    ASSERT_EQ(heap.getMax(), 7);
    ASSERT_EQ(heap.removeMax(), 7);
    ASSERT_EQ(heap.getMax(), 6);
}

TEST_F(MaxHeapTest, HeapifyArrayAndInsert) {
    int n = 7;
    int *inputArray = new int[n]{1, 2, 3, 4, 5, 6, 7};
    MaxHeap heap(inputArray, n);
    ASSERT_EQ(heap.getMax(), 7);
    ASSERT_EQ(heap.removeMax(), 7);
    ASSERT_EQ(heap.getMax(), 6);

    heap.insert(8);
    ASSERT_EQ(heap.getMax(), 8);
    ASSERT_EQ(heap.removeMax(), 8);
    ASSERT_EQ(heap.getMax(), 6);
}

TEST_F(MaxHeapTest, ReallocationAndSize) {
    MaxHeap heap;
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    ASSERT_EQ(heap.getSize(), 5);
    ASSERT_EQ(heap.getMax(), 5);
    ASSERT_EQ(heap.removeMax(), 5);
    ASSERT_EQ(heap.getSize(), 4);
    ASSERT_EQ(heap.removeMax(), 4);
    ASSERT_EQ(heap.getSize(), 3);
}


