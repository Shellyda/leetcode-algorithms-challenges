#include <iostream>
#include <vector>

using std::endl;
using std::vector;

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
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> arr;
        dfs(root, arr);
        return arr[k - 1];
    }

    void dfs(TreeNode *node, vector<int> &arr)
    {
        if (!node)
            return;
        dfs(node->left, arr);
        arr.push_back(node->val);
        dfs(node->right, arr);
    }
};