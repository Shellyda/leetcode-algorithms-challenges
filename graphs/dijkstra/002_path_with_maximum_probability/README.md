# Path with Maximum Probability

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/path-with-maximum-probability/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

Instead of minimizing the _sum_ of edge weights (distances), our goal is to **maximize the _product_ of edge probabilities**.

1.  **Build a graph**: Represent the graph using an adjacency list where each entry stores a destination node and the success probability of traversing that edge. Since the graph is undirected, add edges in both directions.
2.  **Use a Max-Heap**: A priority queue is used as a max-heap to ensure that we always process the node that is currently reachable with the highest probability. We'll store pairs of `{probability, node}`.
3.  **Iterate and Update**:
    - Start with the `start_node` with a probability of `1.0`.
    - In a loop, extract the node with the highest probability from the heap.
    - For each of its neighbors, calculate the new probability of reaching it through the current node (`currentProb * edgeProb`).
    - If this new path is more probable than any previously found path to that neighbor, update its probability and add it to the heap for future exploration.
4.  **Result**: The algorithm terminates when the heap is empty. The answer is the maximum probability recorded for the `end_node`.

## 🕒 Time and Space Complexity

> Let $N$ be the number of nodes and $E$ be the number of edges.

- Time: $O(E \log N)$. Building the graph takes $O(E)$. The main `while` loop processes each edge at most once. For each edge, we might perform a push operation on the priority queue, which costs $O(\log N)$.
- Space: $O(N + E)$. The adjacency list requires $O(N + E)$ space. The `maxProb` vector takes $O(N)$ space, and the priority queue can hold up to $E$ entries in the worst case, taking $O(E)$ space.

## ✅ Solution

```cpp
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges,
                          vector<double> &succProb, int start_node,
                          int end_node)
    {
        unordered_map<int, vector<pair<int, double>>> adj;

        // adding edges in both ways
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i][0], dst = edges[i][1];
            double weight = succProb[i];
            adj[src].push_back({dst, weight});
            adj[dst].push_back({src, weight});
        }

        vector<double> maxProb(n, 0.0);

        priority_queue<pair<double, int>> maxHeap; // using a max heap

        maxProb[start_node] = 1.0;
        maxHeap.push({1.0, start_node});

        while (!maxHeap.empty())
        {
            auto [currentProb, currentNode] = maxHeap.top();
            maxHeap.pop();

            if (currentProb < maxProb[currentNode])
            {
                continue;
            }

            for (auto &neighbor : adj[currentNode])
            {
                int neighborNode = neighbor.first;
                double edgeProb = neighbor.second;

                if (currentProb * edgeProb > maxProb[neighborNode])
                {
                    maxProb[neighborNode] = currentProb * edgeProb;
                    maxHeap.push({maxProb[neighborNode], neighborNode});
                }
            }
        }

        return maxProb[end_node];
    }
};
```
