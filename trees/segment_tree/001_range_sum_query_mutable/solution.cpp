#include <vector>
using std::vector;

struct Node
{
    int sum, L, R;
    Node *left, *right;
    Node(int total, int L, int R)
        : sum(total), L(L), R(R), left(nullptr), right(nullptr) {}
};

class NumArray
{
public:
    Node *root;

    NumArray(vector<int> &nums) { root = build(nums, 0, nums.size() - 1); }

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

    void update(int index, int val) { updateHelper(root, index, val); }
    void updateHelper(Node *root, int index, int val)
    {
        if (root->L == root->R)
        {
            root->sum = val;
            return;
        }
        int M = (root->L + root->R) / 2;
        if (index > M)
        {
            updateHelper(root->right, index, val);
        }
        else
        {
            updateHelper(root->left, index, val);
        }

        root->sum = root->left->sum + root->right->sum;
    }

    int sumRange(int left, int right)
    {
        return sumRangeHelper(root, left, right);
    }
    int sumRangeHelper(Node *root, int L, int R)
    {
        if (L <= root->L && root->R <= R)
            return root->sum;

        if (R < root->L || L > root->R)
            return 0;

        return sumRangeHelper(root->left, L, R) +
               sumRangeHelper(root->right, L, R);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */