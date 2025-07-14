# Path Sum

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/path-sum/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. Base case: If the node is null, return false.
2. Subtract the current node’s value from targetSum.
3. If it’s a leaf node (no left or right child) and targetSum == 0, return true.
4. Otherwise, recursively check left and right subtrees.
5. Return true if either subtree returns true.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n) for recursion stack

## ✅ Solution

```cpp
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        targetSum -= root->val;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum) || (targetSum == 0 && !root->left && !root->right);
    }
};
```
