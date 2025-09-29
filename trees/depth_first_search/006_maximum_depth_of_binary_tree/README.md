Here is the completed description.

# Maximum Depth of Binary Tree

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1.  **Base Case:** If the current node is `null` (representing an empty tree or the child of a leaf node), its depth is 0. This is the termination condition for the recursion.
2.  **Recursive Step:** For any non-null node, we recursively call the function on its left child and its right child to find the depth of the respective subtrees.
3.  **Combine Results:** The depth of the tree rooted at the current node is `1` (for the node itself) plus the **maximum** of the depths of its left and right subtrees.

Essentially, we break the problem down into smaller, identical subproblems until we reach the base case, and then we build the solution back up.

## 🕒 Time and Space Complexity

- **Time:** $O(N)$, where $N$ is the number of nodes in the tree. We must visit every node exactly once to determine the depth.
- **Space:** $O(H)$, where $H$ is the height of the tree. This is because the space is determined by the maximum depth of the recursion call stack.
  - In the **worst case** (a completely skewed or unbalanced tree), the height is $N$, so the space complexity is $O(N)$.
  - In the **best case** (a perfectly balanced tree), the height is $log(N)$, so the space complexity is $O(log N)$.

## ✅ Solution

```cpp
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // Base case: if the tree is empty, its depth is 0.
        if (!root)
            return 0;

        // Recursively find the depth of the left and right subtrees.
        int leftResult = maxDepth(root->left);
        int rightResult = maxDepth(root->right);

        // The depth of the tree is 1 (for the current node)
        // plus the maximum depth of its subtrees.
        int result = 1 + max(leftResult, rightResult);

        return result;
    }
};
```
