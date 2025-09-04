#include <vector>
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