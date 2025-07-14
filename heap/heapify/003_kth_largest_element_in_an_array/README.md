# Kth Largest Element In An Array

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. Use a **max-heap** (`priority_queue<int>`) to store all numbers.

2. Extract the **top (largest) element `k` times**:

   - The first pop gives the largest,
   - the second pop gives the second largest,
   - ...
   - the **k-th pop gives the k-th largest** number.

3. Return that number.

## 🕒 Time and Space Complexity

- Time: O(nlogk)
- Space: O(k)

> Where `n` is the length of the array nums

## ✅ Solution

```cpp
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;

        for (int n : nums)
        {
            pq.push(n);
        }

        int res;

        for (int i = 0; i < k; ++i)
        {
            int top = pq.top();
            if (i == k - 1)
            {
                res = top;
            }

            pq.pop();
        }

        return res;
    }
};
```
