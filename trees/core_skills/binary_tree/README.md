# Binary Tree

## Purpose

- Study the binary tree concept

## Concept

Similar to linked lists, binary trees are another data structure that involve nodes and pointers.

With linked lists, we connected nodes in a straight line with `next` and `prev` pointers. Nodes in a binary tree also have at most two pointers, but we call them the left child and the right child pointers. The first node in a binary tree is referred to as the root node. We draw the pointers down instead of a straight line.

If a node does not have any children, it is classified as a leaf node. If a node has even a single child, either left or right, it would be classified as a non-leaf node.

Unlike linked lists, binary tree node pointers can only point in one direction. As such, cycles are not allowed in binary trees. Mathematically speaking, a binary tree is a connected, undirected graph with no cycles. This means that a leaf node is always guaranteed to exist.

## ✅ Solution

```cpp
class TreeNode
{
public:
    int val_;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        val_ = val;
    }
};
```
