#include "gtest/gtest.h"
#include "double_linked_list/DoubleLinkedList.h"


class DoubleLinkedListTest : public ::testing::Test {

};

TEST_F(DoubleLinkedListTest, PushAndPop) {
    DoubleLinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);

    ASSERT_EQ(list.pop(), 3);
    ASSERT_EQ(list.pop(), 2);
    ASSERT_EQ(list.pop(), 1);
}

TEST_F(DoubleLinkedListTest, UnshiftAndShift) {
    DoubleLinkedList list;
    list.unshift(1);
    list.unshift(2);
    list.unshift(3);

    ASSERT_EQ(list.shift(), 3);
    ASSERT_EQ(list.shift(), 2);
    ASSERT_EQ(list.shift(), 1);
}

TEST_F(DoubleLinkedListTest, AddAtAndRemoveAt) {
    DoubleLinkedList list;
    list.addAt(0, 1);
    list.addAt(1, 3);
    list.addAt(1, 2);

    ASSERT_EQ(list.removeAt(1), 2);
    ASSERT_EQ(list.removeAt(1), 3);
    ASSERT_EQ(list.removeAt(0), 1);
}

TEST_F(DoubleLinkedListTest, Get) {
    DoubleLinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);

    ASSERT_EQ(list.get(0), 1);
    ASSERT_EQ(list.get(1), 2);
    ASSERT_EQ(list.get(2), 3);
}

TEST_F(DoubleLinkedListTest, ListEmptyException) {
    DoubleLinkedList list;

    ASSERT_THROW(list.pop(), std::logic_error);
    ASSERT_THROW(list.shift(), std::invalid_argument);
}

TEST_F(DoubleLinkedListTest, IndexOutOfBoundsException) {
    DoubleLinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);

    ASSERT_THROW(list.get(3), std::invalid_argument);
    ASSERT_THROW(list.addAt(4, 4), std::invalid_argument);
    ASSERT_THROW(list.removeAt(3), std::invalid_argument);
}

TEST_F(DoubleLinkedListTest, PrintListAndPrintReversed) {
    DoubleLinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);

    testing::internal::CaptureStdout();
    list.printList();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1 2 3 \n");

    testing::internal::CaptureStdout();
    list.printReversed();
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "3 2 1 \n");
}
