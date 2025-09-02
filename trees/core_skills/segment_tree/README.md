# Design Segment Tree

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/segmentTree)
- 🚦 Difficulty: 🔴 Hard

## Purpose

Your `SegmentTree` class should support the following operations:

- `SegmentTree(int[] arr)` will initialize a segment tree based on the given array arr. You can assume that the array arr is non-empty.
- `int query(int l, int r)` will return the sum of all elements in the range `[l, r]` inclusive. You can assume that` 0 <= l <= r < arr.length`.
- `void update(int idx, int val)` will update the element at index idx in the original array to be val. You can assume that `0 <= idx < arr.length`.

### Example 1:

```cpp
Input:
["SegmentTree", [1, 2, 3, 4, 5], "query", 0, 2, "query", 2, 4, "update", 3, 0, "query", 2, 4]

Output:
[null, 6, 12, null, 8]
```

### Example 2:

```cpp
Input:
["SegmentTree", [-1, 2, 4], "query", 0, 1, "query", 1, 2, "update", 2, 3, "query", 0, 2]

Output:
[null, 1, 6, null, 4]
```

## Concept

The structure of segment trees is one of the most complex among tree structures.

### Motivation

Suppose we were given a range of values. Then, given a left and a right pointer that defines the range, we want to be able to calculate **the sum of the range**. This is the fundamental textbook problem behind segment trees and this is what we will be focusing on.

Solving this using an array is trivial but to go through the range, in the worst case, takes `O(n)` time. If we want to update a value in an array, it is done in `O(1)` time. Now, segment trees promise to implement both update and perform queries in `O(logn)` time. **Though it adds more overhead to the update function, the tradeoff is that our search function will be much faster**.

**Not too dissimilar to merge sort**, the idea here is to break up the array into segments, by a branching factor of two to be more precise, and have each node represent a progressively smaller range. We break up the array into two equal halves, and each node represents a range (which are basically indices of arrays).

The visual below demonstrates how a segment tree is constructed using an array. The numbers in red represent the sum of the range at that given node. The numbers inside the node represent the range itself, inclusive of both numbers. The text in blue represents the formula for calculating the range.
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/471422ed-b3fb-49ba-f316-89b6afafe900/sharpen=1)

### Implementation

Similar to heaps, segment trees can be constructed using arrays. Recall that heaps are almost complete binary trees where every level is full except possibly the last level. However, segment trees have gaps in the last level, which makes them harder to be implemented with arrays. So, we will implement them using objects of a `SegmentTree` class, which can be conceptualized as nodes.

#### Segment Tree Constructor

We need the following in our `SegmentTree Node` struct:

1. `sum`, which will keep track of the sum at each node.
2. `right` and `left` pointers to the right and left child (similar to binary trees).
3. At any given node, `L` and `R` denote the left and right boundaries of the contained range, respectively.

```cpp
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
    ...
```

#### Building the segment tree

Given an array `nums` and `L` and `R`, we can take a recursive approach. At each level, we calculate `M`, which splits the current range in half, and builds the tree until we hit our base case, where `L == R`, i.e. the range gets exhausted.

To start off, we will initialize a `root` with a sum of `0`. We can then recursively calculate the sum at each node and return the ultimate sum.

```cpp
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
```

#### Update

If we want to update a node sum, we can take in the index that we want to update and the value we want to update it with. The implementation is similar to the `build()` function. Our base case is if we reach a leaf node, we have found our index and we can update the sum to the new value. Then, we will calculate our `M` value. If it is smaller than the index, we will recursively go down the right subtree and if it is greater than the index, we will recursively go down the left subtree.

This works because of the way we split our array

```cpp
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
```

**Let's walk through an example:**

Let `i = 3` and `v = 4`, where i is the index for the update and `v` represents the new value we want to update. Once we get to the base case, i.e. a leaf node, we will update the value and do it recursively.
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/6785c600-60ba-44e4-85c7-b3ae69cb5900/sharpen=1)

#### Range Query

```cpp
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
```

**This is the most important operation of a segment tree - to calculate a range query**. Let's say that we are given the range `0,5`. From the example we shown above, this range is in the root node, which makes it an `O(1)` operation. Of course, this is the best case scenario.

What if we are given a range that requires us to traverse down the tree? Well, we will follow the same recursive procedure. We will recurse down the tree, and calculate the `M`. Given `L` and `R`, if `L > M`, our range query lies on the right. If `R <= M`, our range lies on the left. And, this makes sense because when we calculated `M` in the `build()` function, the left sub-tree had indices `L, M` and right sub-tree has indices `M+1, R`.

In the code above, we have three conditionals. Let's walk through cases under which each conditional would execute.

**1. The base case**

Suppose we are given a range query `[0,5]`. This is the best case scenario where the following piece of code would execute. We can immediately return the sum, which is `22`.

```cpp
 if (L <= root->L && root->R <= R)
            return root->sum; // 22
```

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/f35d5b91-a3fe-49c9-f26b-900507faf900/sharpen=1)

**2. `L <= M` and `R <= M` case**

If we are given the range `[5,5]`, this means that our entire range lies in the right sub-tree. This is because 5>2, where 2 represents the M at our root node.
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/e64320e7-4c29-4aca-e082-bef6791bbb00/sharpen=1)

If we are given the range `[1,1]`, our entire range lies in the left sub-tree, this is because `1<=2` where `2` represents `M` at our root node.
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/debaae9e-c0f0-4042-af04-5220d9597000/sharpen=1)

In theses cases, we will execute the following line.

```cpp
 if (L <= root->L && root->R <= R)
            return root->sum; // returns 3 for [1,1] and 2 for [5,5]
```

**3. Range overlaps with right and left sub-tree**

If we are given a range that does not exist in any node in our `right` or `left` subtree, it must be the case that it lies in both of the subtrees. An example is `[2,4]` as long as it is a valid range.

```cpp
   return query_helper(root->left, L, R) + query_helper(root->right, L, R);
```

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/680787e6-1700-433f-e9f0-68b275c5fa00/sharpen=1)

## 🕒 Time and Space Complexity

The time complexity of the three functions is as follows:

1. `build()` - O(n), where n is the number of nodes our tree contains.
2. `update()` - O(logn), since we are going down the height of the tree, which is a balanced tree, where `h` is the height of the tree, also known as `logn`.
3. `rangeQuery(L, R)` - O(logn), for reasons similar to the `update()` function.

### For current solution operations in general

- Time: O(n)
- Space: O(n)

> Where `n` is the number for elements in the input

## ✅ Solution

```cpp
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
        {
            return new Node(nums[L], L, R);
        }

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
```
