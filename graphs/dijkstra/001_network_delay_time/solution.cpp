#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 1; i <= n; i++)
            adj[i] = vector<pair<int, int>>();

        for (vector<int> time : times)
        {
            int src = time[0], dst = time[1], weight = time[2];
            adj[src].push_back({dst, weight});
        }

        unordered_map<int, int> shortest;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        minHeap.push({0, k}); // cost -> node

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

        if (shortest.size() < n)
            return -1;

        int res = 0;
        for (auto &[node, timeCost] : shortest)
            res = max(res, timeCost);

        return res;
    }
};
