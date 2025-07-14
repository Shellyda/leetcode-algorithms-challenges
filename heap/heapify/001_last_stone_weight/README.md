# Last Stone Weight

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/last-stone-weight/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. Push all stones into a **max-heap** (i.e., priority queue with largest element on top).

2. While there is more than one stone in the heap:

   - Remove the two heaviest stones (`x` and `y`).
   - If they are different (`x != y`), push the difference back into the heap.

3. When done:

   - If one stone is left, return its weight.
   - If no stones left, return `0`.

---

Input:

```cpp
[2,7,4,1,8,1]
```

Steps:

- 8 vs 7 → push 1
- 4 vs 2 → push 2
- 2 vs 1 → push 1
- 1 vs 1 → nothing left

Output: `0`

## 🕒 Time and Space Complexity

- Time: O(nlogn)
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap;
        for (int val : stones)
        { // O(n.logn)

            maxHeap.push(val); // logn
        }

        int res = maxHeap.size() == 1 ? maxHeap.top() : 0;

        while (!maxHeap.empty() && maxHeap.size() != 1) // logn
        {
            int x = maxHeap.top(); // O(1)
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if (x != y)
            {
                y = x < y ? y - x : x - y;

                maxHeap.push(y);
            }

            if (maxHeap.size() == 1)
            {
                res = maxHeap.top();
            }
        }

        return res;
    }
};
```
