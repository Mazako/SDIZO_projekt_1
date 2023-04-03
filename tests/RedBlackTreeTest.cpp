#include <iostream>
#include <gtest/gtest.h>
#include "red_black_tree/RedBlackTree.h"

class RedBlackTreeTest : public ::testing::Test {};

TEST_F(RedBlackTreeTest, Insertion) {
    RedBlackTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    EXPECT_EQ(tree.root->key, 30);
    EXPECT_EQ(tree.root->color, 'b');
    EXPECT_EQ(tree.root->left->key, 20);
    EXPECT_EQ(tree.root->left->color, 'b');
    EXPECT_EQ(tree.root->right->key, 50);
    EXPECT_EQ(tree.root->right->color, 'r');
}

TEST_F(RedBlackTreeTest, Deletion) {
    RedBlackTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.deleteNode(50);

    tree.printTreeDiagram();

    EXPECT_EQ(tree.root->key, 30);
}

TEST_F(RedBlackTreeTest, Rotations) {
    RedBlackTree tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(50);

    tree.rightRotate(tree.root);

    EXPECT_EQ(tree.root->key, 20);
    EXPECT_EQ(tree.root->right->key, 30);
    EXPECT_EQ(tree.root->right->right->key, 40);
    EXPECT_EQ(tree.root->right->right->right->key, 50);

    tree.leftRotate(tree.root->right);

    EXPECT_EQ(tree.root->key, 20);
    EXPECT_EQ(tree.root->right->key, 40);
    EXPECT_EQ(tree.root->right->left->key, 30);
    EXPECT_EQ(tree.root->right->right->key, 50);
}

TEST_F(RedBlackTreeTest, FindMin) {
    RedBlackTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    RedBlackNode *min_node = tree.findMin(tree.root);

    EXPECT_EQ(min_node->key, 20);
}

TEST_F(RedBlackTreeTest, FindMax) {
    RedBlackTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    RedBlackNode *max_node = tree.findMax(tree.root);

    EXPECT_EQ(max_node->key, 80);
}

TEST_F(RedBlackTreeTest, FindNode) {
    RedBlackTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    RedBlackNode *found_node = tree.findNode(40);

    ASSERT_NE(found_node, nullptr);
    EXPECT_EQ(found_node->key, 40);

}