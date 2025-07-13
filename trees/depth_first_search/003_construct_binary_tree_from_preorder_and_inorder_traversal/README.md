# Construct Binary Tree from Preorder and Inorder Traversal

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Hash Map + Depth First Search

### Preorder Traversal:

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/9388095e-8f09-4725-fc1d-27988a291c00/sharpen=1)

### Inorder Traversal:

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/e8717d2e-69c7-4ec2-ce9c-6d8753d3cc00/sharpen=1)

> The order in which the nodes are visited is represented by the numbers in blue next to the node.

```cpp
preorder = [3,9,20,15,7]
inorder  = [9,3,15,20,7]
```

1. `preorder[0] = 3` → `root`
2. `inorder` shows in `3` left is `9`, and in right are `15, 20, 7`.
3. Call recursively to `root->left` (`9`) and then to `root->right` (`20` with two children `15` and `7`)
4. `buildTree` result:

```cpp
      3
     / \
    9  20
       / \
      15  7
```

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
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
```
