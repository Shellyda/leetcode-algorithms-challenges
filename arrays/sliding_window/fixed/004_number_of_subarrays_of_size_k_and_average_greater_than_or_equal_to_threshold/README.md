# Number of subArrays of size K and Average greater than or equal to threshold

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/submissions/1736713359/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach 01 - Brute force

- It uses a **queue** (`window`) to store the current `k` elements in a sliding window.
- For each element in `arr`:
  1. Push it into the queue.
  2. When the queue reaches size `k`, check if the average ≥ `threshold` using `avgInRange`.
  3. If yes, increment the counter `res`.
  4. Remove the oldest element from the queue (FIFO behavior) to slide the window forward.
- Return `res` after processing all elements.

## 🕒 Time and Space Complexity

- Time: O(n\*k)
- Space: O(n)

> Where `n` is the size of the array `arr` and `k` is the size of the sub-array

## ✅ Solution

```cpp
class Solution
{
private:
    bool avgInRange(queue<int> currWindow, int threshold)
    {
        int sum = 0, k = currWindow.size();
        while (!currWindow.empty())
        {
            sum += currWindow.front();
            currWindow.pop();
        }

        int avg = sum / k;

        return avg >= threshold;
    }

public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        queue<int> window; // queue -> FIFO
        int r = 0, res = 0;

        for (int r : arr)
        {
            window.push(r);

            if (window.size() == k)
            {
                if (avgInRange(window, threshold))
                    res++;
                window.pop();
            }
        }

        return res;
    }
};
```

## 💡 Approach 02 - Sliding window II

- For each number in `arr`:

  1. Add it to the queue and to the running sum.
  2. When the window reaches size `k`, compute the average in O(1) and compare with `threshold`.
  3. If the condition is met, increment the result counter.
  4. Remove the oldest element from both the queue and the running sum to slide the window.

- Return the final count after processing all elements.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(k)

> Where `n` is the size of the array `arr` and `k` is the size of the sub-array

## ✅ Solution

```cpp
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        queue<int> window;
        int sum = 0, res = 0;

        for (int num : arr)
        {
            window.push(num);
            sum += num;

            if (window.size() == k)
            {
                int avg = sum / k;
                if (avg >= threshold)
                    res++;

                sum -= window.front();
                window.pop();
            }
        }

        return res;
    }
};
```
