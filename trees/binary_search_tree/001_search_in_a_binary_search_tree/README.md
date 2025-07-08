# Search in a Binary Search Tree

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/search-in-a-binary-search-tree/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Use the concept: all left side of root is smaller and right side is bigger than the root value
- Did it using recursion

## 🕒 Time and Space Complexity

- Time: O(H)
- Space: O(H) for recursion stack

> Where `H` is the height of given tree

## ✅ Solution

```cpp
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return root;
        }

        if (val > root->val)
        {
            return searchBST(root->right, val);
        }
        else if (val < root->val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return root;
        }
    }
};
```
