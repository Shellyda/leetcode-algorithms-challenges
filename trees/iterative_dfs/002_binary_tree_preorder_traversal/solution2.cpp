#include <vector>
#include <stack>
using std::stack;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stack;
        vector<int> res;
        TreeNode *curr = root;

        while (curr || !stack.empty())
        {
            if (curr)
            {
                res.push_back(curr->val);
                stack.push(curr->right);
                curr = curr->left;
            }
            else
            {
                curr = stack.top();
                stack.pop();
            }
        }

        return res;
    }
};