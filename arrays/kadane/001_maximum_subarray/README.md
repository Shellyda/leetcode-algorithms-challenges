# Maximum Subarray

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/maximum-subarray/submissions/1724858375/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach 01 - Brute force

The brute force way to approach this would be to go through every single subarray and calculate the sum, while keeping track of the maximum sum.

> For every iteration of our outer for loop, our inner loop does linear work. This makes the complexity O(n^2).

While this approach works, it is not the most efficient. The intuition behind **Kadane's algorithm** is that:

1. If all elements in the array are positive, the maximum sum subarray is the entire array.
2. If we ever have a negative sum subarray, that's the case we want to avoid.

## 🕒 Time and Space Complexity

- Time: O(n^2)
- Space: O(1)

## ✅ Solution

```cpp
// Brute Force: O(n^2)
int bruteForce(vector<int>& nums) {
    int maxSum = nums[0];

    for (int i = 0; i < nums.size(); i++) {
        int curSum = 0;
        for (int j = i; j < nums.size(); j++) {
            curSum += nums[j];
            maxSum = max(maxSum, curSum);
        }
    }
    return maxSum;
}
```

## 💡 Approach 02 - Kadane's algorithm

Kadane's algorithm tells us that there is a way to calculate the largest sum by only making one pass on the array, bringing the complexity down to linear time

> Since we are looking for the largest sum, it is a good idea to avoid negative numbers because we know that contradicts what the question is asking for. Negative numbers will only make our sum smaller.

But sometimes we may need to include a negative number to get the surrounding positive numbers.

- For example, the array `[6, -2, 7]` has a maximum sum of `11`. If we exclude the `-2`, we can't include both `6` and `7`.
- But that's not always the case. If we have `[1, -3, 7]`, the maximum sum is 7. Including the `-3` isn't worth it just to get the `1`.
- The pattern is that if we ever have a negative subarray sum, we should discard it and start a new subarray. This is because we know that the sum will only get smaller if we include it.

1. Kadane's algorithm runs one loop.
2. We keep track of the `curSum` by adding the current element to it.
3. Before we add the current element, we check if the `curSum` is negative. If it is, we reset it to zero.
4. We initialize the maxSum to the first element in the array. This is technically a subarray of size `1`. (We could have initialized it to any other element in the array.)
5. We update the `maxSum` by taking the maximum of the current sum and the maximum sum so far.

> It's possible that every element in the array is negative. In that case, the maximum sum would be the largest negative number.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/f16c1a92-9cbd-43d4-ae6b-0d143e833d00/sharpen=1)

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
// Kadane's Algorithm: O(n)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curSum = 0;
        int maxSum = nums[0];

        for (int n : nums)
        {
            curSum = max(curSum, 0) + n;

            maxSum = max(curSum, maxSum);
        }

        return maxSum;
    }
};
```

## 💡 Approach 03 - Sliding Window variation of Kadane's

Sometimes, a problem may ask to return the actual subarray containing the largest sum, instead of just the sum itself. Previously, we didn't have two explicit pointers that kept track of the subarray in the previous implementation but we can actually do this by keeping track of a "window". A window in this case denotes a contiguous subarray that does not break our constraint of the sum staying positive.

To do this, we can have a left pointer, `L = 0`, and a right pointer, `R`. The left and right pointers define the boundaries of our window (inclusive).

Since we want the subarray with the maximum sum, we can also have two other pointers, `maxL` and `maxR`, which keep track of the subarray that contains the maximum sum so far. This way, we don't lose them when we move `L` and `R`.

Similar to before, if our current sum becomes negative, we can move our left pointer all the way to our right pointer. This means that our constraint was broken and we remove all elements from the left and start a new window.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/15050f42-b760-47c8-813b-af6bc43bde00/sharpen=1)

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
// Sliding window variation of Kadane's: O(n)
vector<int> slidingWindow(vector<int> nums) {
    int maxSum = nums[0];
    int curSum = 0;
    int maxL = 0, maxR = 0;
    int L = 0;

    for (int R = 0; R < nums.size(); R++) {
        if (curSum < 0) {
            curSum = 0;
            L = R;
        }
        curSum += nums[R];
        if (curSum > maxSum) {
            maxSum = curSum;
            maxL = L;
            maxR = R;
        }
    }
    return vector<int>{maxL, maxR};
}
```
