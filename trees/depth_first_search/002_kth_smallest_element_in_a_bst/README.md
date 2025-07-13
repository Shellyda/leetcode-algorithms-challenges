# Kth Smallest Element in a BST

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- An inorder traversal will only print the nodes in a sorted order if the tree is a binary search tree

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> arr;
        dfs(root, arr);
        return arr[k - 1];
    }

    void dfs(TreeNode *node, vector<int> &arr)
    {
        if (!node)
            return;
        dfs(node->left, arr);
        arr.push_back(node->val);
        dfs(node->right, arr);
    }
};
```
