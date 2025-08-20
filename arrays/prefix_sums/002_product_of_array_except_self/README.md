# Product of Array Except Self

- 🧩 Problem link: [Leetcode](https://neetcode.io/problems/products-of-array-discluding-self/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

**Step 1 — prefix pass (left → right):**

- `res[i]` will store the product of all elements before `i`.
- Initialize `res` with `1`s.
- Loop from `i = 1..n-1`:

  - `res[i] = res[i - 1] * nums[i - 1]`.
  - This means each `res[i]` contains the cumulative product of all numbers to the left of `i`.

**Step 2 — postfix pass (right → left):**

- Use a variable `postfix = 1` to keep track of the product of elements to the right of `i`.
- Loop from `i = n-1..0`:

  - Multiply `res[i]` by the accumulated `postfix`.
  - Update `postfix *= nums[i]`.

At the end, each position `i` has:
`res[i] = product of left side * product of right side`.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};
```
