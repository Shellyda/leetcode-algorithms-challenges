# Subtree of Another Tree

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/subtree-of-another-tree/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1.  `isSubtree(root, subRoot)`: This function traverses the `root` tree. For each node it visits, it calls a helper function, `isSameTree`, to check for an exact match with `subRoot`.

    - If `isSameTree` returns `true`, we have found the subtree, and the result is `true`.
    - If not, the search continues by recursively calling `isSubtree` on the left and right children of the current node (`isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)`).

2.  `isSameTree(p, q)`: This is a standard helper function that checks if two trees are structurally and valuewise identical. It recursively compares `p` and `q`, ensuring that their values are equal and that their respective left and right subtrees are also identical.

The base cases handle null nodes: a null `subRoot` is always a subtree, but a non-null `subRoot` cannot be a subtree of a null `root`.

## 🕒 Time and Space Complexity

Let `m` be the number of nodes in `root` and `n` be the number of nodes in `subRoot`.

- **Time:** $O(m \cdot n)$

  - In the worst case, we traverse every node of the `root` tree (`m` nodes). For each of these nodes, we call `isSameTree`, which then traverses every node of the `subRoot` tree (`n` nodes) to check for a match.

- **Space:** $O(m)$
  - The space complexity is determined by the maximum depth of the recursion stack. In the worst case (a skewed `root` tree), the recursion depth of `isSubtree` can be `m`.

## ✅ Solution

```cpp
class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!subRoot)
            return true;
        if (!root)
            return false;

        if (isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

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
