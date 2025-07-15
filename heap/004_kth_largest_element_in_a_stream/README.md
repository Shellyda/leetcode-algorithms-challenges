# Kth Largest Element In a Stream

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. **Use a min-heap (priority queue with smallest element on top)** to keep the **k largest elements** seen so far.

2. During initialization (`constructor`):

   - Add each number in `nums` to the heap.
   - If the heap size exceeds `k`, remove the smallest element.
   - This ensures the heap always contains the top `k` largest elements.

3. On each `add(val)` call:

   - Push the new value into the heap.
   - If the heap size exceeds `k`, pop the smallest element.
   - The **top of the min-heap** is always the **kth largest element**, so return `minHeap.top()`.

---

- The **smallest element in the heap of size k** is the **kth largest overall**.
- Maintaining the heap at size `k` keeps time and space efficient:
  **Each `add()` is O(log k)** and space is **O(k)**.

---

```cpp
KthLargest kth(3, [4,5,8,2]);

kth.add(3);  // returns 4
kth.add(5);  // returns 5
kth.add(10); // returns 5
kth.add(9);  // returns 8
kth.add(4);  // returns 8
```

## 🕒 Time and Space Complexity

- Time: O(m \* logk)
- Space: O(k)

> Where `m` is the number of calls made to `add()`

## ✅ Solution

```cpp
class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
```
