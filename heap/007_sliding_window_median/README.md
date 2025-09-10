# Sliding Window Median

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/sliding-window-median)
- 🚦 Difficulty: 🔴 Hard

## 💡 Approach 01 - Two Heaps Brute force

- `small` is a max-heap that stores the smaller half of numbers.
- `large` is a min-heap that stores the larger half.
- Together they let us get the median in **O(1)** once balanced.

The algorithm works like this:

1. For each window of size `k`, it inserts all elements into the two heaps.
2. When the window is full, it calculates the median and pushes it into `res`.
3. Then it **clears both heaps and starts over** from the next index, rebuilding the heaps from scratch.
4. This repeats until the end of the array.

Because it rebuilds the heaps for every window, the complexity is **O(n \* k log k)** instead of the optimal **O(n log k)**.

So this is basically a “reset and rebuild” approach using heaps, **correct but inefficient** compared to a real sliding-window solution with insert + remove.

## 🕒 Time and Space Complexity

- Time: O(n\*klogk)
- Space: O(n−k+1) space for output array.

> Where `n` is the size of the array `nums` and `k` is the size of the sliding window

## ✅ Solution 01

```cpp
class Solution
{
public:
    priority_queue<double> small;                                  // maxHeap
    priority_queue<double, vector<double>, greater<double>> large; // minHeap

    vector<double> res;

    // O(n*klogk)

    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        int l = 0, r = 0, balance = k;

        while (r < nums.size())
        {
            if (balance > 0)
            {
                balance--;
                insert(nums[r]);
                r++;
            }
            else
            {
                double median = getMedian();
                res.push_back(median);

                // Clear

                balance = k;
                l++;
                r = l;

                small = priority_queue<double>();
                large = priority_queue<double, vector<double>, greater<double>>();
            }
        }

        if (balance == 0)
            res.push_back(getMedian()); // get the last case

        return res;
    }

private:
    void insert(int num)
    {
        if (!large.empty() && num > large.top())
            large.push(num);
        else
            small.push(num);

        if (small.size() > large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }
        else if (large.size() > small.size() + 1)
        {
            small.push(large.top());
            large.pop();
        }
    }

    double getMedian()
    {
        if (small.size() > large.size())
        {
            return (double)small.top();
        }
        else if (large.size() > small.size())
        {
            return (double)large.top();
        }

        return (double)(large.top() + small.top()) / 2.0;
    }
};
```

## 💡 Approach 02 - Two Heaps with SW

- `small` (maxHeap) → stores the **smaller half** of the numbers.
- `large` (minHeap) → stores the **larger half** of the numbers.

This way:

- If `k` is odd, the median is simply the top of `small`.
- If `k` is even, the median is the average of the tops of both heaps.

To handle removals (when an element leaves the window), we use a **`delayed` hash map**:

- It marks numbers that are “expired” and should be ignored.
- Whenever the top of a heap is expired, we discard it with `cleanHeap`.

### Algorithm Flow

1. **Expand the window with `r` (right index)**

   - Insert the new number using `addNum`.
   - It goes into `small` if it’s less than or equal to `small.top()`, otherwise into `large`.
   - Call `rebalance` to ensure heap sizes differ by at most 1.

2. **When the window size reaches `k`**

   - Compute the median using `getMedian` and push it into `res`.
   - Call `removeNum(nums[l])` to mark the element leaving the window.
   - Increment `l` to shrink the window from the left.

3. **Lazy removal with `removeNum`**

   - Instead of deleting directly from a heap (inefficient in `priority_queue`), we mark the element in `delayed`.
   - If that element happens to be on top, we immediately call `cleanHeap` to discard it.
   - `cleanHeap` keeps popping until the top is valid.

4. **Rebalancing (`rebalance`)**

   - If `small` has more than 1 element extra, move its top into `large`.
   - If `large` has more elements than `small`, move its top into `small`.
   - After each move, clean the affected heap’s top if it’s expired.

5. **Median calculation (`getMedian`)**

   - If `k` is odd → return `small.top()`.
   - If `k` is even → return the average of `small.top()` and `large.top()`.

- Adding a number: **O(log k)**.
- Removing a number (lazy): **O(log k)**.
- Each number is inserted and removed exactly once.
  Overall complexity: **O(n log k)**.

This is much better than the earlier approach (**O(n·k log k)**), which rebuilt the window from scratch each time.

## 🕒 Time and Space Complexity

- Time: O(nlogk)
- Space: O(n−k+1) space for output array.

> Where `n` is the size of the array `nums` and `k` is the size of the sliding window

## ✅ Solution 02

```cpp
class Solution
{
public:
    priority_queue<int> small;                            // maxHeap
    priority_queue<int, vector<int>, greater<int>> large; // minHeap
    unordered_map<int, int> delayed;                      // lazy removal
    int smallSize = 0, largeSize = 0;

    vector<double> res;

    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        int l = 0, r = 0;

        while (r < nums.size())
        {
            addNum(nums[r]);

            if (r - l + 1 == k) // checking window size
            {
                res.push_back(getMedian(k));
                removeNum(nums[l]); // remove the num in the very left
                l++;
            }

            r++;
        }

        return res;
    }

private:
    void addNum(int num)
    {
        if (small.empty() || num <= small.top())
        {
            small.push(num);
            smallSize++;
        }
        else
        {
            large.push(num);
            largeSize++;
        }
        rebalance();
    }

    void removeNum(int num)
    {
        delayed[num]++; // mark future removal

        if (!small.empty() && num <= small.top())
        {
            smallSize--;
            if (num == small.top())
                cleanHeap(small);
        }
        else
        {
            largeSize--;
            if (!large.empty() && num == large.top())
                cleanHeap(large);
        }
        rebalance();
    }

    void rebalance()
    {
        if (smallSize > largeSize + 1)
        {
            large.push(small.top());
            small.pop();
            smallSize--;
            largeSize++;
            cleanHeap(small);
        }
        else if (largeSize > smallSize)
        {
            small.push(large.top());
            large.pop();
            largeSize--;
            smallSize++;
            cleanHeap(large);
        }
    }

    template <typename T>
    void cleanHeap(priority_queue<int, vector<int>, T> &heap)
    {
        while (!heap.empty() && delayed.count(heap.top()))
        {
            int x = heap.top();
            if (--delayed[x] == 0)
                delayed.erase(x);
            heap.pop();
        }
    }

    double getMedian(int k)
    {
        if (k % 2 == 1)
            return small.top();
        return ((double)small.top() + (double)large.top()) / 2.0;
    }
};
```
