Aqui está uma versão completa e bem estruturada do write-up para **Network Delay Time**:

---

# Network Delay Time

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/network-delay-time/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **Build adjacency list:**

   - Represent the graph as `node -> list of (neighbor, weight)` pairs.

2. **Use a min-heap (priority queue):**

   - Each element is `(current_time, node)`.
   - Start with `(0, k)`.

3. **Dijkstra’s relaxation:**

   - Pop the smallest time from the heap.
   - If the node already has a shortest path assigned, skip it.
   - Otherwise, set its shortest time and push all neighbors with updated costs into the heap.

4. **Final result:**

   - If not all nodes are reached, return `-1`.
   - Otherwise, return the **maximum shortest time** among all nodes (the last node to receive the signal).

```cpp
build adjacency list
initialize minHeap with (0, k)
initialize shortest as empty map

while heap not empty:
    time, node = pop from heap
    if node already in shortest: continue
    shortest[node] = time
    for each neighbor:
        if neighbor not in shortest:
            push (time + weight, neighbor) into heap

if size(shortest) < n:
    return -1
else:
    return max value in shortest
```

## 🕒 Time and Space Complexity

- Time Complexity:

  - Building adjacency list: **O(E)**, where `E` = number of edges.
  - Dijkstra with heap: **O((V + E) log V)**, where `V = n`.
  - Total: O((V + E) log V).

- Space Complexity:

  - Adjacency list: **O(V + E)**.
  - Min-heap and shortest map: **O(V)**.
  - Total: O(V + E).

## ✅ Solution

```cpp
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adj;

        // build adjacency list
        for (int i = 1; i <= n; i++)
            adj[i] = vector<pair<int, int>>();

        for (vector<int> time : times)
        {
            int src = time[0], dst = time[1], weight = time[2];
            adj[src].push_back({dst, weight});
        }

        unordered_map<int, int> shortest;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k}); // cost, node

        // Dijkstra
        while (!minHeap.empty())
        {
            auto [w1, n1] = minHeap.top();
            minHeap.pop();

            if (shortest.count(n1))
                continue;

            shortest[n1] = w1;

            for (auto &p : adj[n1])
            {
                int n2 = p.first, w2 = p.second;
                if (!shortest.count(n2))
                {
                    minHeap.push({w1 + w2, n2});
                }
            }
        }

        // check if all nodes were reached
        if (shortest.size() < n)
            return -1;

        // return the max shortest time
        int res = 0;
        for (auto &[node, timeCost] : shortest)
            res = max(res, timeCost);

        return res;
    }
};
```
