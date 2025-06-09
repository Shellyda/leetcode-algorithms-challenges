// Definition for a binary tree node.
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
    TreeNode *findMin(TreeNode *root)
    {
        TreeNode *curr = root;

        while (curr && curr->left)
        {
            curr = curr->left;
        }

        return curr;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;

        if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // found the number

            // case 01 - The target node has one child or no children
            if (!root->left)
            {
                return root->right;
            }
            else if (!root->right)
            {
                return root->left;
            }
            else
            {                                         // case 0 - The target node has two children
                TreeNode *min = findMin(root->right); // can choose left or right here
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
        }

        return root;
    }
};