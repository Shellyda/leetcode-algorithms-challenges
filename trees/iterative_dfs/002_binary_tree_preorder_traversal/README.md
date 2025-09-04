# Binary Tree Preorder Traversal

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/binary-tree-preorder-traversal/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach 01 - Recursion

- Preorder traversal is **Node → Left → Right**.
- The recursion directly follows that order:

  1. Visit the current node (`res.push_back(root->val)`),
  2. Recurse on the left child,
  3. Recurse on the right child.

- If the current node is `null`, just return (no work to do).

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution 01

```cpp
class Solution
{
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return res;

        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return res;
    }
};
```

## 💡 Approach 02 - Iterative DFS

Recall that **preorder** traversal involves visiting:

1. Visiting the current node.
2. Then visiting the left subtree.
3. And finally visiting the right subtree.

To implement this iterative, we will still loop through the left pointers of the tree. However, we will print the value of the node before traversing the left pointer. We will also push the right pointer to the stack before traversing the left pointer, rather than inserting the current node.

This way, we can print the current node before traversing the left subtree, and then traverse the right subtree.

```cpp
void preorder(TreeNode* root) {
    vector<TreeNode*> stack;
    TreeNode* curr = root;

    while (curr || stack.size()) {
        if (curr) {
            cout << curr->val_ << endl;
            if (curr->right_) {
                stack.push_back(curr->right_);
            }
            curr = curr->left_;
        } else {
            curr = stack.back();
            stack.pop_back();
        }
    }
}
```

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/2a9b99c3-5d7f-4e77-b7d9-c008a2481200/sharpen=1)

### Code components

1. **Stack to remember right children**

   - In preorder, you visit the current node, then left, then right.
   - To avoid recursion, the algorithm temporarily saves the right child on the stack while it goes left.

2. **Pointer `curr`**

   - Points to the current node being processed.
   - Goes left whenever possible.
   - When `curr` becomes null, it means the left branch ended, so the algorithm pops a right child from the stack.

3. **Traversal process**

   - If `curr` is not null:

     - Visit it (`res.push_back(curr->val)`).
     - Push its right child on the stack (to visit later).
     - Move to the left child.

   - Else (if `curr` is null):

     - Pop from the stack → continue with the saved right subtree.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution 02

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> res;
        TreeNode* curr = root;

        while (curr || !stack.empty()) {
            if (curr) {
                res.push_back(curr->val);
                stack.push(curr->right);
                curr = curr->left;
            } else {
                curr = stack.top();
                stack.pop();
            }
        }

        return res;
    }
};
```
