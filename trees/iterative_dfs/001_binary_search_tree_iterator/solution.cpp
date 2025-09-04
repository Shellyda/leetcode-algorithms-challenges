#include <stack>
using std::stack;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
private:
    TreeNode *curr;
    stack<TreeNode *> stack;

public:
    BSTIterator(TreeNode *root)
    {
        curr = root;
    }

    int next()
    {
        while (curr)
        {
            stack.push(curr);
            curr = curr->left;
        }

        TreeNode *node = stack.top(); // the last left leaf
        stack.pop();                  // remove it
        curr = node->right;           // move to right node
        return node->val;
    }

    bool hasNext()
    {
        return curr || !stack.empty();
    }
};