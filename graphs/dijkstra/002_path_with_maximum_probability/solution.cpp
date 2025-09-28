#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

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