# Combinations

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/combinations)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach 01 - All possible combinations

This approach is similar to that of the subsets. We iterate through `1−5` in our decision tree and make a decision to include or exclude the current number we are on.

We are also restricted by the number of elements we can include in our combination. Since `k=2`, our base case hits when `curComb.length == k`. This is why when we reach `[1,2]`, we don't need to go any farther.

```cpp
#include <vector>

using std::vector;

// Given n numbers (1 - n), return all possible combinations
// of size k. (n choose k math problem).
// Time: O(k * 2^n)
vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> combs;
    vector<int> curCombs;
    helper(1, curCombs, combs, n, k);
    return combs;
}

void helper(int i, vector<int>& curComb, vector<vector<int>>& combs, int n, int k) {
    if (curComb.size() == k) {
        combs.push_back(vector<int>(curComb));
        return;
    }
    if (i > n) return;

    // decision to include i
    curComb.push_back(i);
    helper(i + 1, curComb, combs, n, k);
    curComb.pop_back();

    // decision to NOT include i
    helper(i + 1, curComb, combs, n, k);
}
```

This approach will result in a decision tree with a branching factor of `2` and a height of `n`. We will also need to create a deep copy of each generate combination, which will be of size `k`.

Thus, the overall time complexity is `O(k \* 2^n)`.

You might notice that the above code is very similar to the subsets lesson with some small differences:

1. In our `helper` function, `i` denotes the current number (from `1` to `n`) we are on.
2. `currComb` represents the current combination.
3. combs represents the list of lists which will contain each `currComb`.
4. `k` represents the size of the target combination.
5. Our base case hits when the length of the `currComb` hits `k`. After exploring combinations including each `i`, we backtrack and explore other combinations that exclude `i`. We repeat this until `i == n`.

## 🕒 Time and Space Complexity

- Time: O(k \* 2^n)
- Space: O(k)

## ✅ Solution 01

```cpp
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> currComb;

        dfs(1, currComb, res, n, k);

        return res;
    }

private:
    void dfs(int index, vector<int> &currComb, vector<vector<int>> &res, int n,
             int k)
    {
        if (currComb.size() == k)
        {
            res.push_back(currComb);
            return;
        }

        if (index > n)
            return;

        currComb.push_back(index);
        dfs(index + 1, currComb, res, n, k);

        currComb.pop_back();
        dfs(index + 1, currComb, res, n, k);
    }
};
```

## 💡 Approach 02 - C(n, k) = n! / k!\*(n-k)!

This notation reads, "How many ways are there to choose `k` objects from a set of `n` elements?" or "`N` choose `K`".

In the previous solution there are a lot of wasted steps where we are skipping elements, and this results in a decision tree that is of size `2^n`.

We can use a more optimized approach that is `O(k∗C(n,k))` where `C(n,k)` is the number of combinations we need to generate.

Instead of choose which elements to include or exclude, we can simply choose which elements to include.

For the first element, we can choose from `1` to `n`.

For the next element, we can choose any except for the one we just chose.

The easiest way to keep track of this and also eliminate duplicate solutions at the same time is to do this: only choose elements in **ascending order**.

1. Choose from `1` to `n`.
2. Choose from `x+1` to `n` where `x` is the element we chose in `step 1`.

This way each combination is always generated in sorted order, which is useful because it means if we generate `[1,2]` we will never generate the duplicate `[2,1]`.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/eb7bd54a-ad01-49cb-c007-4f2ee2052900/sharpen=1)

Given `n=5` and `k=2`, we get:

> 5!/2!\*(5-2)! = `10`

```cpp
// Time: O(k * C(n, k))
vector<vector<int>> combinations2(int n, int k) {
    vector<vector<int>> combs;
    vector<int> curCombs;
    helper2(1, curCombs, combs, n, k);
    return combs;
}

void helper2(int i, vector<int>& curComb, vector<vector<int>>& combs, int n, int k) {
    if (curComb.size() == k) {
        combs.push_back(vector<int>(curComb));
        return;
    }
    if (i > n) return;

    for (int j = i; j < n + 1; j++) {
        curComb.push_back(j);
        helper2(j + 1, curComb, combs, n, k);
        curComb.pop_back();
    }
}
```

## 🕒 Time and Space Complexity

- Time: O(k \* C(n, k))
- Space: O(k)

## ✅ Solution 02

```cpp
// Combination math background: C(n, k) = n! / k!*(n-k)!
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> currComb;

        dfs(1, currComb, res, n, k);

        return res;
    }

private:
    void dfs(int index, vector<int>& currComb, vector<vector<int>>& res, int n,
             int k) {
        if (currComb.size() == k) {
            res.push_back(currComb);
            return;
        }

        if (index > n)
            return;

        // C(n,k) = n! / k!*(n-k)!
        for(int j = index; j < n + 1; j++){
            currComb.push_back(j);
            dfs(j+1, currComb, res, n, k);
            currComb.pop_back();
        }
    }
};
```
