# K Closest Points to Origin

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/k-closest-points-to-origin/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **Compute squared distance** from the origin `(0, 0)` for each point:

$$
\text{distance} = x^2 + y^2
$$

(You don't need square root since the relative order remains the same.)

2. Store each point along with its distance in a **min-heap** (priority queue):

   - Heap stores `pair<distance, point>` to sort by smallest distance.

3. **Extract the top `k` elements** from the heap — these are the closest points.

---

Input:

```cpp
points = [[1,3],[−2,2]], k = 1
```

Steps:

- Distances: (1,3) → 10, (−2,2) → 8
- Heap: \[(8, \[-2,2]), (10, \[1,3])]
- Result: \[\[-2,2]]

## 🕒 Time and Space Complexity

- Time: O(k \*logn)
- Space: O(n)

> Where `n` is the length of the array points

## ✅ Solution

```cpp
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>>
            minHeap;

        for (auto p : points)
        {
            int distance = p[0] * p[0] + p[1] * p[1];

            pair<int, vector<int>> result = {distance, p};

            minHeap.push(result);
        }

        vector<vector<int>> res;

        for (int i = 0; i < k && !minHeap.empty(); ++i)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
```
