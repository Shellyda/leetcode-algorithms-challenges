// Graph implementation using adjacency list
#include <unordered_set>
#include <unordered_map>
using std::unordered_map;
using std::unordered_set;

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
