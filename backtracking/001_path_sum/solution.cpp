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