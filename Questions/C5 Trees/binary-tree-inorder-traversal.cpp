#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int _val)
    {
        val = _val;
    }
};

class Solution
{
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return result;

        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);

        return result;
    }
};