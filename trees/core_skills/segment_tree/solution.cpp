#include <vector>
using std::vector;

struct Node
{
    int sum, L, R;
    Node *left;
    Node *right;
    Node(int total, int L, int R) : sum(total), L(L), R(R),
                                    left(nullptr), right(nullptr) {}
};

class SegmentTree
{
public:
    Node *root;

    SegmentTree(vector<int> &nums)
    {
        root = build(nums, 0, nums.size() - 1);
    }

    Node *build(vector<int> &nums, int L, int R)
    {
        if (L == R)
            return new Node(nums[L], L, R);

        int M = (L + R) / 2;
        Node *root = new Node(0, L, R);
        root->left = build(nums, L, M);
        root->right = build(nums, M + 1, R);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    void update(int index, int val)
    {
        update_helper(root, index, val);
    }

    void update_helper(Node *root, int index, int val)
    {
        if (root->L == root->R)
        {
            root->sum = val;
            return;
        }

        int M = (root->L + root->R) / 2;
        if (index > M)
        {
            update_helper(root->right, index, val);
        }
        else
        {
            update_helper(root->left, index, val);
        }
        root->sum = root->left->sum + root->right->sum;
    }

    int query(int L, int R)
    {
        return query_helper(root, L, R);
    }

    int query_helper(Node *root, int L, int R)
    {
        if (L <= root->L && root->R <= R)
            return root->sum;

        if (R < root->L || L > root->R)
            return 0;

        return query_helper(root->left, L, R) + query_helper(root->right, L, R);
    }
};
