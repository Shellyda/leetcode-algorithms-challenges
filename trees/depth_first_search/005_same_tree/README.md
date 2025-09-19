# Same Tree

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/same-tree/description)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. **Base cases**:

   - If both nodes are `nullptr`, they are equal → return `true`.
   - If only one is `nullptr`, they are different → return `false`.

2. **Value check**:

   - If the values of the two nodes are different → return `false`.

3. **Recursive check**:

   - Recursively check both the **left** and **right** subtrees.
   - Return `true` only if both subtrees are equal.

## 🕒 Time and Space Complexity

- Time: O(n), because every node is visited once
- Space: O(h), due to recursion stack, where `h` is the height of the tree.

## ✅ Solution

```cpp
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```
