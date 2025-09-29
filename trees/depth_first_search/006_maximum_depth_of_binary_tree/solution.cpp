#include <algorithm>
using std::max;

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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftResult = maxDepth(root->left);
        int rightResult = maxDepth(root->right);

        int result = 1 + max(leftResult, rightResult);

        return result;
    }
};