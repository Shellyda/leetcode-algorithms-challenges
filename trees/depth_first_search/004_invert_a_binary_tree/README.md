# Invert a Binary Tree

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/invert-binary-tree/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

At each node:

1. If the node is `null`, return it.
2. Recursively invert the left and right subtrees.
3. Swap the left and right children.
4. Return the current node.

This inverts the tree **top-down**, swapping each subtree as we go.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n) for recursion stack

## ✅ Solution

```cpp
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        TreeNode *temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);

        return root;
    }
};
```
