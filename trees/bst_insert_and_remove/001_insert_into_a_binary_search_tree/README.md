# Insert into a Binary Search Tree

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/insert-into-a-binary-search-tree/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Add node in `binTree` in the leaf, using recursion

## 🕒 Time and Space Complexity

- Time: O(H)
- Space: O(H) for the recursion stack

> Where `H` is the height of the given binary search tree.

## ✅ Solution

```cpp
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);

        if (val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }

        return root;
    }
};
```
