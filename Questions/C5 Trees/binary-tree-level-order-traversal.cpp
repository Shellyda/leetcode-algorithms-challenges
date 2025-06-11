#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

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
