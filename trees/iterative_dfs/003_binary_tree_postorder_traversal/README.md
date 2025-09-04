# Binary Tree Postorder Traversal

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/binary-tree-postorder-traversal/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach 01 - Recursion

Postorder order is **Left → Right → Node**.
The recursion follows exactly that sequence:

1. First, visit the **left subtree**.
2. Then, visit the **right subtree**.
3. Finally, process the **current node** (push its value into `res`).

- If the current node is `null`, simply return.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution 01

```cpp
class Solution
{
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return res;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);

        return res;
    }
};
```

## 💡 Approach 02 - Iterative DFS

**Postorder** traversal deals with traversing the left child, right child and then the root. This one is more complicated than the previous two.

We will be making use of two stacks. In this case, we will have a `visit` stack and another stack called `stack`.

The `visit` and `stack` stacks will always be the same size. The stack stack will be used to store the nodes we are currently processing, while the `visit` stack will be used to keep track of whether we have previously visited the corresponding node in `stack` or not.

We can then run a while loop, i.e. `while stack is not null` (since our `visited` and `stack` is the exact same size). Using this, we will pop from our `stack` and `visited`. If our `curr` is not `null`, we check if we have visited it.

```cpp
void postorder(TreeNode* root) {
    vector<TreeNode*> stack = {root};
    vector<bool> visit = {false};

    while (stack.size()) {
        TreeNode* curr = stack.back();
        bool visited = visit.back();
        stack.pop_back();
        visit.pop_back();
        if (curr) {
            if (visited) {
                cout << curr->val_ << endl;
            } else {
                stack.push_back(curr);
                visit.push_back(true);
                stack.push_back(curr->right_);
                visit.push_back(false);
                stack.push_back(curr->left_);
                visit.push_back(false);
            }
        }
    }
}
```

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/86bbabf3-602d-444c-441b-575098980100/sharpen=1)

### Code components

Since postorder is **Left → Right → Node**, the tricky part is that you can’t process a node until _both_ its children are done.
This solution simulates recursion using:

- a `stack` of nodes,
- a parallel `visit` array of booleans (to track whether a node has already been seen once).

1. Start by pushing the root with `visited = false`.
2. Pop `(node, visited)` from the stack:

   - If `node` is `null`, skip.
   - If `visited == true`, it means both children were already pushed, so now we can process the node (`res.push_back(node->val)`).
   - If `visited == false`:

     - Push the node back with `visited = true` (to process later).
     - Push its right child with `visited = false`.
     - Push its left child with `visited = false`.
       → This guarantees Left → Right → Node order.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution 02

```cpp
class Solution
{
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode *root)
    {
        postorder(root);
        return res;
    }
    void postorder(TreeNode *root)
    {
        vector<TreeNode *> stack = {root};
        vector<bool> visit = {false};

        while (stack.size())
        {
            TreeNode *curr = stack.back();
            bool visited = visit.back();
            stack.pop_back();
            visit.pop_back();
            if (curr)
            {
                if (visited)
                {
                    res.push_back(curr->val);
                }
                else
                {
                    stack.push_back(curr);
                    visit.push_back(true);
                    stack.push_back(curr->right);
                    visit.push_back(false);
                    stack.push_back(curr->left);
                    visit.push_back(false);
                }
            }
        }
    }
};
```
