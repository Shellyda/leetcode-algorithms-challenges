# Design Graph

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/graph)
- 🚦 Difficulty: 🟡 Medium

## Purpose

Design a directed Graph class.

Your `Graph` class should support the following operations:

- `Graph()` will initialize an empty directed graph.
- `void addEdge(int src, int dst)` will add an edge from `src` to `dst` if it does not already exist. If either `src` or `dst` do not exist, add them to the graph.
- `bool removeEdge(int src, int dst)` will remove the edge from src to dst if it exists. Return whether the edge was removed. Either `src` or `dst` may not exist in the graph.
- `bool hasPath(int src, int dst)` will return whether there is a path from `src` to `dst`. Assume both `src` and `dst` exist in the graph.

### Constraints:

- Each vertex value will be a unique integer.
- Multiple edges from one vertex to another are not allowed.
- A vertex will not have an edge to itself, but the graph may contain a cycle.
- The graph is not necessarily connected (there may be disconnected components).

### Example 1:

```cpp
Input:
["addEdge", 1, 2, "addEdge", 2, 3, "hasPath", 1, 3, "hasPath", 3, 1, "removeEdge", 1, 2, "hasPath", 1, 3]

Output:
[null, null, true, false, true, false]
```

### Example 2:

```cpp
Input:
["addEdge", 1, 2, "addEdge", 2, 3, "addEdge", 3, 1, "hasPath", 1, 3, "hasPath", 3, 1]

Output:
[null, null, null, true, true]
```

## ✅ Solution

```cpp
class Graph
{
private:
    // Adjacency list
    unordered_map<int, unordered_set<int>> adjList;

    // Internal DFS method to check if there's a path
    bool hasPathDFS(int src, int dst, unordered_set<int> &visited)
    {
        if (src == dst)
        {
            return true;
        }
        visited.insert(src);
        for (const int &neighbor : adjList[src])
        {
            if (visited.find(neighbor) == visited.end())
            {
                if (hasPathDFS(neighbor, dst, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Alternatively, you can use BFS for hasPath
    /*
    bool hasPathBFS(int src, int dst) {
        unordered_set<int> visited;
        deque<int> queue = { src };
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop_front();
            if (curr == dst) {
                return true;
            }
            visited.insert(curr);
            for (const int &neighbor : adjList[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push_back(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return false;
    }
    */

public:
    Graph() {}

    // Add an edge from src to dst
    void addEdge(int src, int dst)
    {
        // If src or dst don't exist, add them
        adjList[src].insert(dst);
    }

    // Remove the edge from src to dst, if it exists
    bool removeEdge(int src, int dst)
    {
        // Check if src and dst exist in the graph
        if (adjList.find(src) == adjList.end() || adjList[src].find(dst) == adjList[src].end())
        {
            return false;
        }
        // Remove the edge
        adjList[src].erase(dst);
        return true;
    }

    // Check if there's a path from src to dst
    bool hasPath(int src, int dst)
    {
        unordered_set<int> visited;
        return hasPathDFS(src, dst, visited);
    }
};
```
