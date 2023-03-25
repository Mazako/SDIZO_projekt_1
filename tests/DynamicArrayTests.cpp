//
// Created by micha on 25.03.2023.
//
#include "gtest/gtest.h"
#include "dynamic_array/DynamicArray.h"
class DynamicArrayTest : public ::testing::Test {

};


TEST_F(DynamicArrayTest, AddFunction) {
    DynamicArray *arr = new DynamicArray();
    arr->add(10);
    arr->add(20);
    arr->add(30);
    EXPECT_EQ(arr->size, 3);
    EXPECT_EQ(arr->array[0], 10);
    EXPECT_EQ(arr->array[1], 20);
    EXPECT_EQ(arr->array[2], 30);
}

TEST_F(DynamicArrayTest, RemoveFunction) {
    DynamicArray *arr = new DynamicArray();
    arr->add(10);
    arr->add(20);
    arr->add(30);
    int removedValue = arr->remove(1);
    EXPECT_EQ(removedValue, 20);
    EXPECT_EQ(arr->size, 2);
    EXPECT_EQ(arr->array[0], 10);
    EXPECT_EQ(arr->array[1], 30);
}

TEST_F(DynamicArrayTest, AddAtFunction) {
    DynamicArray *arr = new DynamicArray();
    arr->add(10);
    arr->add(20);
    arr->add(30);
    arr->addAt(1, 25);
    EXPECT_EQ(arr->size, 4);
    EXPECT_EQ(arr->array[0], 10);
    EXPECT_EQ(arr->array[1], 25);
    EXPECT_EQ(arr->array[2], 20);
    EXPECT_EQ(arr->array[3], 30);
}

TEST_F(DynamicArrayTest, InvalidArgument) {
    DynamicArray *arr = new DynamicArray();
    arr->add(10);
    arr->add(20);
    EXPECT_THROW(arr->remove(2), std::invalid_argument);
}

TEST_F(DynamicArrayTest, SizeTooBig) {
    DynamicArray *arr = new DynamicArray();
    arr->add(10);
    arr->add(20);
    EXPECT_THROW(arr->addAt(5, 30), std::invalid_argument);
}
