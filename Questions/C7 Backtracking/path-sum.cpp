#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    int key;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int key, int val)
    {
        this->key = key;
        this->val = val;
    }
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        targetSum -= root->val;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum) || (targetSum == 0 && !root->left && !root->right);
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode(0, 1);
    TreeNode *n1 = new TreeNode(1, 2);
    TreeNode *n2 = new TreeNode(1, 3);

    root->left = n1;
    root->right = n2;

    s.hasPathSum(root, 5);

    return 0;
}