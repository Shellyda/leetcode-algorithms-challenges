# Dijkstra Algorithm

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/dijkstra)
- 🚦 Difficulty: 🟡 Medium

## Purpose

**Implement Dijkstra's shortest path algorithm.**

Given a weighted, directed graph, and a starting vertex, return the shortest distance from the starting vertex to every vertex in the graph.

**Input:**

- `n` - the number of vertices in the graph, where `(2 <= n <= 100)`. Each vertex is labeled from `0` to `n - 1`.
- `edges` - a list of tuples, each representing a directed edge in the form `(u, v, w)`, where `u` is the source vertex, `v` is the destination vertex, and `w` is the weight of the edge, where `(1 <= w <= 10)`.
- `src` - the source vertex from which to start the algorithm, where `(0 <= src < n)`.

**Note: If a vertex is unreachable from the source vertex, the shortest path distance for the unreachable vertex should be `-1`.**

### Example 1:

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/482027d5-fb4e-4a3c-d710-ec60cbead600/sharpen=1)

```cpp
Input:
n = 5
edges = [[0,1,10], [0,2,3], [1,3,2], [2,1,4], [2,3,8], [2,4,2], [3,4,5]]
src = 0

Output:
{{0:0}, {1:7}, {2:3}, {3:9}, {4:5}}
```

## Concept

**Dijkstra's Algorithm**

Having already covered BFS, we will now cover another shortest path algorithm - Dijkstra's algorithm. The downside of using BFS is that it only works when the graph is unweighted - i.e. where the default weight of each edge is 1.

If we are given the following unweighted graph: `edges = [[A,B], [A,C], [B,D], [C,B], [C,D], [C,E], [D,E]]`, and are asked to find the shortest path from `A` (source node) to `D` (destination node), we can apply classic BFS and keep adding the weights until we get to `D`.

**Because all the weights are the same, BFS gives the shortest path in terms of the amount of vertices we visit. However, this fails when we have different weights for different edges as shown below.**

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/1dad3ca2-1b38-4391-578f-a3e790386400/sharpen=1)

Dijkstra's algorithm is used to find the shortest path to all nodes in a weighted graph. It is similar to BFS, except it operates on weighted graphs. Because Dijkstra's algorithm operates on different weights, it will prioritize finding the shortest path such that the path to each destination is the "lightest".

In other words, BFS does not revisit nodes but Dijkstra will, if it finds a shorter path (in terms of weight).

### The setup

**Suppose we are faced with the following question:**

> Q: Starting from A, find the length of the shortest path to every other node.

Given the previous weighted graph, and a source vertex, `A`, we want to find the shortest paths from `A` to every other vertex in our graph. It should be noted that when we say "shortest", it means "lightest", i.e. paths that have the smallest total weight (the sum of the weight for the edges on the path).

Starting from `A`, the shortest path to reach `C` is `A -> C`, with a weight of `3`. And, this is guaranteed to be the shortest path. This makes sense because `A -> B` costs `10`, so even if there was a path to `C` through `B`, it would never be less than `4`. This only works if we have no negative weights. The visual below demonstrates the graph, `edges = [[A,B,10], [A,C,3], [B,D,2], [C,B,4], [C,D,8], [C,E,2], [D,E,5]]`, and the numbers under the letters denote the shortest path to that vertex.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/7d2b9f24-92b2-4bdd-7f1f-0eeafafdc800/sharpen=1)

### Walk-through of Dijsktra's algorithm

Let's go over how we came to the above result. Since `A` is the source vertex, and no self-loop, distance from `A` to `A` is 00. From `A`, we can take `A -> B` (10) and `A -> C` (3). From `B` and `C`, we can take `B -> D` (2), `C -> B` (4), `C -> E` (2), `C -> D` (8).

\*\*For `B`, we can update our shortest path to 7 since `B` can be reached through `C` 3 + 4 = 7 < 10.The only way to reach `C` is `A -> C`, so shortest path to `C` is 3.`D` can be reached through `A -> B`, `A -> C -> B` or `A -> C`. The shortest path is `A -> C -> B -> D`, i.e. 3 + 4 + 2= 9.`E`'s shortest path is `A -> C -> E`, i.e. 3 + 2 = 5. Other valid paths to `E` are `A -> B -> D -> E`, `A -> C -> D -> E`, and `A -> B -> D -> E`.

- For `B`, we can update our shortest path to 7 since `B` can be reached through `C` 3+4=7<10.
  **7**
  **3+4=7<10**
- The only way to reach `C` is `A -> C`, so shortest path to `C` is 3.
  **3**
- `D` can be reached through `A -> B`, `A -> C -> B` or `A -> C`. The shortest path is `A -> C -> B -> D`, i.e. 3+4+2=9.
  **3+4+2=9**
- `E`'s shortest path is `A -> C -> E`, i.e. 3+2=5. Other valid paths to `E` are `A -> B -> D -> E`, `A -> C -> D -> E`, and `A -> B -> D -> E`.
  **3+2=5**

> Dijkstra's algorithm is a classic example of a greedy algorithm. A greedy algorithm makes the optimal choice at each step, meaning it selects the best option available at each step. In this case, the smallest weight.

### Implementation

Since we are choosing the path with the minimum weight, a min-heap is the perfect data structure here. Each "node" in the min-heap will contain the node letter and the cost associated with that node, like `<cost, node>`.

> Notice that cost is the first element in the tuple. This is because we want to sort the min-heap by the cost.

Since we are optimizing for the shortest path, it might be the case that we have to add the same vertex many times to get the shortest possible path. We will also declare a hashmap to map our vertices and their respective shortest paths.

> The visual below demonstrates the step-by-step process of how the min-heap implementation works to find the shortest path. We always pop the node with the lowest cost.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/d620c4ce-5017-4c62-6e53-55fb39c2d600/sharpen=1)

The code implementation of Dijkstra is rather simple. Firstly, given a pair of `edges`, we want to build an adjacency list so that we can traverse the graph. `adj` represents this adjacency list. We will initialize our list with the source `s` vertex, `d` (destination) and `w` (weight). This part connects all of the vertices together with their weights.

We then use another hashmap `shortest`, which contains our vertices and their respective shortest paths. This is what we will return. We will then add our `src` to our `minHeap` and its weight, `0`. We will then run a while loop until our `minHeap` is empty. Because it is a min-heap, we will always be popping the edge with the smallest weight. If we have already visited a vertex, i.e. it has been popped before, we will skip this vertex. Otherwise, we will visit all the neighbors of the popped vertex, and if the neighbor is unvisited, we add it to our `minHeap`, with its respective weight. In this particular implementation, `shortest` will only return once we have exhausted the `minHeap`, even if it requires skipping the vertices.

## 🕒 Time and Space Complexity

The time complexity for this algorithm can be written as O(E logE), where E is the number of edges. Recall that in the worst case, each vertex is connected to the other, i.e. V^2. In the worst case, we might have every single edge inside of our heap. Since insertion and removal from a heap is logn, this gives us a total of O(E logE).

- Time: O(E logE)
- Space: O(V+E)

## ✅ Solution

```cpp
class Solution
{
public:
    // Implementation for Dijkstra's shortest path algorithm
    unordered_map<int, int> shortestPath(int n, vector<vector<int>> &edges, int src)
    {
        // Build adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; i++)
        {
            adj[i] = vector<pair<int, int>>();
        }

        // s = src, d = dst, w = weight
        for (vector<int> &edge : edges)
        {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back({d, w});
        }

        // Compute shortest paths
        unordered_map<int, int> shortest;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});

        while (!minHeap.empty())
        {
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            int w1 = curr.first, n1 = curr.second;

            if (shortest.count(n1) > 0)
                continue;
            shortest[n1] = w1;

            for (pair<int, int> &edge : adj[n1])
            {
                int n2 = edge.first, w2 = edge.second;
                if (shortest.count(n2) == 0)
                    minHeap.push({w1 + w2, n2});
            }
        }

        // Fill in missing nodes
        for (int i = 0; i < n; i++)
        {
            if (shortest.find(i) == shortest.end())
            {
                shortest[i] = -1;
            }
        }

        return shortest;
    }
};
```
