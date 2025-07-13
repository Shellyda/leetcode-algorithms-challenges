# Binary Tree Inorder Traversal

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/binary-tree-inorder-traversal/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- An inorder traversal will recursively visit all the nodes in the left subtree, then visit the parent node and finally visit all the nodes in the right subtree. In this case, "visit" could mean anything from printing the node to performing some operation on it.
- Since we know all values to the left of a node are smaller, this means we won't hit our base case until we reach the left-most node which is also the smallest node. After visiting this, we will traverse up, visit the parent and then visit the right-subtree. The visual below shows this process.
  ![alt text](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/e8717d2e-69c7-4ec2-ce9c-6d8753d3cc00/sharpen=1)
  > The order in which the nodes are visited is represented by the numbers in blue next to the node.

**obs.:** It is important to note that an inorder traversal will only print the nodes in a sorted order if the tree is a binary search tree.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n) space for the recursion stack, and also, O(n) for the output array

## ✅ Solution

```cpp
class Solution
{
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return result;

        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);

        return result;
    }
};
```
