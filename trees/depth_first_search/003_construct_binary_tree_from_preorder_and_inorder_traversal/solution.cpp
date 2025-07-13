#include <iostream>
#include <vector>
#include <unordered_map>

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
    int preIdx = 0;
    unordered_map<int, int> indices;

    TreeNode *dfs(vector<int> &preorder, int l, int r)
    {
        if (l > r)
            return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode *root = new TreeNode(rootVal);
        int mid = indices[rootVal];
        root->left = dfs(preorder, l, mid - 1);
        root->right = dfs(preorder, mid + 1, r);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            indices[inorder[i]] = i; // Save in the hashMap the nodes indices
        }
        return dfs(preorder, 0, inorder.size() - 1); // binSearch
    }
};