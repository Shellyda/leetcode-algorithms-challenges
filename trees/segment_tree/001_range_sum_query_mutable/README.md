# Range Sum Query Mutable

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/range-sum-query-mutable/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Build a **Segment tree** where:

  - Each leaf represents a single element of the array.
  - Each internal node stores the **sum of its children**.

- This allows:

  - **Update** in `O(log n)` (only update the path from the leaf to the root).
  - **Range sum query** in `O(log n)` (combine results from relevant segments).

### Code Components

#### **1. Node structure**

```cpp
struct Node {
    int sum, L, R;
    Node *left, *right;
    Node(int total, int L, int R)
        : sum(total), L(L), R(R), left(nullptr), right(nullptr) {}
};
```

- Each node stores:

  - `sum`: total sum of the interval `[L, R]`.
  - `L, R`: the range covered by this node.
  - `left, right`: pointers to child nodes.

#### **2. Build function**

```cpp
Node* build(vector<int>& nums, int L, int R) {
    if (L == R) return new Node(nums[L], L, R);

    int M = (L + R) / 2;
    Node* root = new Node(0, L, R);
    root->left = build(nums, L, M);
    root->right = build(nums, M + 1, R);
    root->sum = root->left->sum + root->right->sum;
    return root;
}
```

- Recursively builds the tree:

  - Base case: leaf node (`L == R`).
  - Otherwise, split into `[L, M]` and `[M+1, R]`, build recursively, and store the sum.

#### **3. Update**

```cpp
void update(int index, int val) { updateHelper(root, index, val); }

void updateHelper(Node* root, int index, int val) {
    if (root->L == root->R) {
        root->sum = val;  // leaf update
        return;
    }
    int M = (root->L + root->R) / 2;
    if (index > M) updateHelper(root->right, index, val);
    else updateHelper(root->left, index, val);

    root->sum = root->left->sum + root->right->sum; // recalc sum
}
```

- Walk down the tree to the correct leaf, update it.
- On the way back up, **recalculate sums** for all ancestors.

#### **4. Range sum query**

```cpp
int sumRange(int left, int right) {
    return sumRangeHelper(root, left, right);
}

int sumRangeHelper(Node* root, int L, int R) {
    if (L <= root->L && root->R <= R) return root->sum;   // fully inside range
    if (R < root->L || L > root->R) return 0;             // completely outside

    return sumRangeHelper(root->left, L, R) +
           sumRangeHelper(root->right, L, R);             // partial overlap
}
```

- **3 cases:**

  1. Node completely inside `[L, R]` → use its sum directly.
  2. Node completely outside `[L, R]` → ignore (return 0).
  3. Partial overlap → query both children and add.

## 🕒 Time and Space Complexity

- **Build:** `O(n)`
- **Update:** `O(log n)`
- **Range query:** `O(log n)`

* Time: O(logn) in general
* Space: O(n)

> Where `logn` is the height of the segment tree

## ✅ Solution

```cpp
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
```
