#include <gtest/gtest.h>
#include "binary_search_tree/BinarySearchTree.h"

class BinarySearchTreeTest : public ::testing::Test {

};

TEST_F(BinarySearchTreeTest, InsertSingleNode) {
    BinarySearchTree bst;
    bst.insertNode(5);

    BstNode *root = bst.findNode(5);
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->data, 5);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
}

TEST_F(BinarySearchTreeTest, InsertMultipleNodes) {
    BinarySearchTree bst;
    bst.insertNode(5);
    bst.insertNode(3);
    bst.insertNode(8);

    BstNode *root = bst.findNode(5);
    BstNode *left = bst.findNode(3);
    BstNode *right = bst.findNode(8);

    ASSERT_NE(root, nullptr);
    ASSERT_NE(left, nullptr);
    ASSERT_NE(right, nullptr);

    EXPECT_EQ(root->left, left);
    EXPECT_EQ(root->right, right);
}

TEST_F(BinarySearchTreeTest, DeleteNodeWithNoChildren) {
    BinarySearchTree bst;
    bst.insertNode(5);
    bst.insertNode(3);
    bst.insertNode(8);

    bst.deleteNode(3);
    BstNode *deletedNode = bst.findNode(3);
    EXPECT_EQ(deletedNode, nullptr);

    BstNode *root = bst.findNode(5);
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right->data, 8);
}

TEST_F(BinarySearchTreeTest, DeleteNodeWithOneChild) {
    BinarySearchTree bst;
    bst.insertNode(5);
    bst.insertNode(3);
    bst.insertNode(8);
    bst.insertNode(7);

    bst.deleteNode(8);
    BstNode *deletedNode = bst.findNode(8);
    EXPECT_EQ(deletedNode, nullptr);

    BstNode *root = bst.findNode(5);
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->right->data, 7);
}

TEST_F(BinarySearchTreeTest, DeleteNodeWithTwoChildren) {
    BinarySearchTree bst;
    bst.insertNode(5);
    bst.insertNode(3);
    bst.insertNode(8);
    bst.insertNode(7);
    bst.insertNode(9);

    bst.deleteNode(8);
    BstNode *deletedNode = bst.findNode(8);
    EXPECT_EQ(deletedNode, nullptr);

    BstNode *root = bst.findNode(5);
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->right->data, 9);
    EXPECT_EQ(root->right->left->data, 7);
}

TEST_F(BinarySearchTreeTest, FindMinAndFindMax) {
    BinarySearchTree bst;
    bst.insertNode(5);
    bst.insertNode(3);
    bst.insertNode(8);
    bst.insertNode(2);
    bst.insertNode(4);
    bst.insertNode(7);
    bst.insertNode(9);
    BstNode *minNode = bst.findMin(bst.head);
    BstNode *maxNode = bst.findMax(bst.head);

    ASSERT_NE(minNode, nullptr);
    ASSERT_NE(maxNode, nullptr);

    EXPECT_EQ(minNode->data, 2);
    EXPECT_EQ(maxNode->data, 9);
}

TEST_F(BinarySearchTreeTest, TreeDepth) {
    BinarySearchTree bst;

    EXPECT_EQ(bst.treeDepth(bst.head), 0);

    bst.insertNode(5);
    EXPECT_EQ(bst.treeDepth(bst.head), 1);

    bst.insertNode(3);
    bst.insertNode(8);
    EXPECT_EQ(bst.treeDepth(bst.head), 2);

    bst.insertNode(9);
    EXPECT_EQ(bst.treeDepth(bst.head), 3);
}
