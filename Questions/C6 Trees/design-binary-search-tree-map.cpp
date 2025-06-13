#include <vector>

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

class TreeMap
{
private:
    TreeNode *root;

    TreeNode *findMin(TreeNode *node)
    {
        while (node && node->left)
        {
            node = node->left;
        }

        return node;
    }

    TreeNode *findMax(TreeNode *node)
    {

        while (node && node->right)
        {
            node = node->right;
        }

        return node;
    }

    TreeNode *addHelper(TreeNode *root, TreeNode *newNode)
    {
        if (!root)
            return newNode;

        if (newNode->key > root->key)
        {
            root->right = addHelper(root->right, newNode);
        }
        else if (newNode->key < root->key)
        {
            root->left = addHelper(root->left, newNode);
        }
        else
        {
            root->val = newNode->val;
        }

        return root;
    }

    TreeNode *removeHelper(TreeNode *root, int key)
    {
        if (!root)
            return root;

        if (key > root->key)
        {
            root->right = removeHelper(root->right, key);
        }
        else if (key < root->key)
        {
            root->left = removeHelper(root->left, key);
        }
        else
        {
            // found key

            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;

            TreeNode *minNode = findMin(root->right); // can use findMax or findMin here
            root->key = minNode->key;
            root->val = minNode->val;
            root->right = removeHelper(root->right, minNode->key);
        }

        return root;
    }

    void showInOrder(TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return;

        showInOrder(root->left, arr);
        arr.push_back(root->key);
        showInOrder(root->right, arr);
    }

public:
    TreeMap()
    {
        root = nullptr;
    }

    void insert(int key, int val)
    {
        TreeNode *newNode = new TreeNode(key, val);

        if (!root)
        {
            root = newNode;
        }
        else
        {
            addHelper(root, newNode);
        }
    }

    int get(int key)
    {
        TreeNode *curr = root;

        while (curr && curr->key != key)
        {
            if (key > curr->key)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        return curr ? curr->val : -1;
    }

    int getMin()
    {
        if (!root)
            return -1;

        return findMin(root)->val;
    }

    int getMax()
    {
        if (!root)
            return -1;

        return findMax(root)->val;
    }

    void remove(int key)
    {
        root = removeHelper(root, key);
    }

    std::vector<int> getInorderKeys()
    {
        vector<int> arr;
        showInOrder(root, arr);

        return arr;
    }
};
