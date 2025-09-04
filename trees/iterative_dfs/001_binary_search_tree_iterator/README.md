# Binary Search Tree Iterator

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/binary-search-tree-iterator/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

The recursive approach for performing DFS is trivial.
Recursion makes use of a stack under the hood. In the iterative version, we will declare our own stack(s) to perform the same operations.

### Implementation

Recall that **inorder** traversal involves visiting:

1. The left child (including it's entire subtree).
2. Then visiting the current node.
3. And finally visiting the right child (including its entire subtree).

We will declare a `curr` pointer, which will point to the current node that we are processing. Once our `curr` pointer points at a node, we will add it to the `stack`. After this, we will update our `curr` pointer to be `curr.left`. If our `curr` points to null, we can pop from the `stack`, print the node's value and traverse the right subtree.

```cpp
void inorder(TreeNode* root) {
    vector<TreeNode*> stack;
    TreeNode* curr = root;

    while (curr || stack.size()) {
        if (curr) {
            stack.push_back(curr);
            curr = curr->left_;
        } else {
            curr = stack.back();
            stack.pop_back();
            cout << curr->val_ << endl;
            curr = curr->right_;
        }
    }
};
```

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/630a2832-9363-42fc-b49a-07274360bd00/sharpen=1)

### Code components:

1. **Stack for simulation**

   - Instead of recursion, it uses a `stack` to keep track of nodes.
   - The stack always holds the path from the root down to the "next" node to return.

2. **Pointer `curr`**

   - `curr` moves down the left subtree.
   - Each step pushes nodes onto the stack until the leftmost is reached.

3. **The `next()` function**

   - While `curr` exists → push it to the stack and go left.
   - When there are no more left children, pop from the stack → that’s the smallest unvisited node.
   - After popping, move `curr` to the right child, because in-order traversal goes **Left → Node → Right**.
   - Return the popped node’s value.

4. **The `hasNext()` function**

   - Checks if there are still nodes to visit:

     - either `curr` is not null (still exploring),
     - or the stack is not empty (nodes waiting to be processed).

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

> If `n` is the number of nodes, and we are doing O(1) work at each node, then the time complexity is O(n). This is also be referred to as O(h) where `h` is the height of the tree.

## ✅ Solution

```cpp
class BSTIterator
{
private:
    TreeNode *curr;
    stack<TreeNode *> stack;

public:
    BSTIterator(TreeNode *root)
    {
        curr = root;
    }

    int next()
    {
        while (curr)
        {
            stack.push(curr);
            curr = curr->left;
        }

        TreeNode *node = stack.top(); // the last left leaf
        stack.pop();                  // remove it
        curr = node->right;           // move to right node
        return node->val;
    }

    bool hasNext()
    {
        return curr || !stack.empty();
    }
};
```
