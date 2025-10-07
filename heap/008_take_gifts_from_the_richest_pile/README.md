# Take Gifts From the Richest Pile

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/take-gifts-from-the-richest-pile/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

We use a max heap (priority queue) to always access the richest pile efficiently. For each of the `k` operations, we remove the largest pile, take its square root (rounded down), and put it back into the heap. After all operations, we sum the remaining piles to get the answer.

## 🕒 Time and Space Complexity

- Time: O(k log n + n log n), where n is the number of piles. Building the heap takes O(n), each of the k operations takes O(log n), and summing the heap takes O(n log n) in the worst case.
- Space: O(n), for storing the heap.

## ✅ Solution

```cpp
class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<long long> maxHeap(gifts.begin(), gifts.end());
        while (k--)
        {
            int root = sqrt(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(root);
        }

        long long sum;

        while (!maxHeap.empty())
        {
            long long top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }

        return sum;
    }
};
```
