# Binary Tree Level Order Traversal

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. Initialize the `queue`:

   - If the `root` is not `null`, push it into the `queue`

2. While the `queue` is not `empty`:

   - Create a temporary list `lvSublist` to store values at the current level
   - Store the current size of the `queue` (len) — this represents the number of nodes at the current level

3. For each node in this level:

   - Remove the node from the `front` of the `queue`

4. Add its value to `lvSublist`

   - If it has a `left child`, push it into the `queue`
   - If it has a `right child`, push it into the `queue`

5. After processing all nodes at that level:

   - Add `lvSublist` to the final result

6. Return result, which is a list of lists, where each inner list contains the values at one level of the `tree`

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;

        // start queue
        if (root)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            vector<int> lvSublist;

            int len = q.size(); // make wait to update counter
            for (int i = 0; i < len; i++)
            {
                TreeNode *curr = q.front(); // curr front node

                lvSublist.push_back(curr->val); // add node to sublist lv

                q.pop(); // remove node

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            result.push_back(lvSublist);
        };

        return result;
    }
};
```
