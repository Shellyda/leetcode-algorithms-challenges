#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

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
