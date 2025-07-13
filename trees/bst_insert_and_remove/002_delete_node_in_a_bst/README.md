# Delete Node in a BST

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/delete-node-in-a-bst/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Search like `binSearch` using the `binSearchTree` concept when find the number, do this:
  1. If The target node has one child or no children
  2. Else The target node has two children -> use `findMin` choosing the `root->right` or `root->left` node to follow here and set `root->val = min->val` and delete `root->right` node

## 🕒 Time and Space Complexity

- Time: O(H)
- Space: O(H) for the recursion stack

> Where `H` is the height of the given binary search tree.

## ✅ Solution

```cpp
class Solution
{
public:
    TreeNode *findMin(TreeNode *root)
    {
        TreeNode *curr = root;

        while (curr && curr->left)
        {
            curr = curr->left;
        }

        return curr;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;

        if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // found the number

            // case 01 - The target node has one child or no children
            if (!root->left)
            {
                return root->right;
            }
            else if (!root->right)
            {
                return root->left;
            }
            else
            {
                // case 0 - The target node has two children
                TreeNode *min = findMin(root->right); // can choose left or right here
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
        }

        return root;
    }
};
```
