
// --- Intuitive pseudocode in python with O(n^2) solution time complexity

// # Definition for a binary tree node.
// # class TreeNode:
// #     def __init__(self, val=0, left=None, right=None):
// #         self.val = val
// #         self.left = left
// #         self.right = right

// class Solution:
//     def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
//         if not preorder or not inorder:
//             return None

//         root = TreeNode(preorder[0])
//         mid = inorder.index(preorder[0])
//         root.left = self.buildTree(preorder[1 : mid + 1], inorder[:mid])
//         root.right = self.buildTree(preorder[mid + 1 :], inorder[mid + 1 :])
//         return root

//// -- THE SAME SOLUTION ABOVE BUT USING C++

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if (preorder.empty() || inorder.empty()) {
//             return nullptr;
//         }

//         TreeNode* root = new TreeNode(preorder[0]);
//         auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
//         vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
//         vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
//         vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
//         vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());
//         root->left = buildTree(leftPre, leftIn);
//         root->right = buildTree(rightPre, rightIn);
//         return root;
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    int preIdx = 0;
    int inIdx = 0;

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int limit)
    {
        if (preIdx >= preorder.size())
            return nullptr;
        if (inorder[inIdx] == limit)
        {
            inIdx++;
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[preIdx++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return dfs(preorder, inorder, INT_MAX);
    }
};