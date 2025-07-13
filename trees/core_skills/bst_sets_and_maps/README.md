# Design a Binary Search Tree class - Sets and Maps

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/binarySearchTree)
- 🚦 Difficulty: 🟡 Medium

You will design a Tree Map, which maps an integer `key` to an integer `value`. Your `Tree` class should support the following operations:

- `TreeMap()` will initialize an binary search tree map.
- `void insert(int key, int val)` will map the `key` to the value and insert it into the tree.
- `int get(int key)` will return the value mapped with the `key`. If the `key` is not present in the tree, return `-1`.
- `int getMin()` will return the value mapped to the smallest `key` in the tree. If the tree is empty, return `-1`.
- `int getMax()` will return the value mapped to the largest key in the tree. If the tree is empty, return `-1`.
- `void remove(int key)` will remove the key-value pair with the given key from the tree.
- `int[] getInorderKeys()` will return an array of the keys in the tree in ascending order.

### Note:

- The tree should be ordered by the keys.
- The tree should not contain duplicate keys. If the key is already present in the tree, the original key-value pair should be overridden with the new key-value pair.

### Example 1:

```cpp
Input:
["insert", 1, 2, "get", 1, "insert", 4, 0, "getMin", "getMax"]

Output:
[null, 2, null, 2, 0]
```

### Example 2:

```cpp
Input:
["insert", 1, 2, "insert", 4, 2, "insert", 3, 7, "insert", 2, 1, "getInorderKeys", "remove", 1, "getInorderKeys"]

Output:
[null, null, null, null, [1, 2, 3, 4], null, [2, 3, 4]]
```

## ✅ Solution

```cpp
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
```
