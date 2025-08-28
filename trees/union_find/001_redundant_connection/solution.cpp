#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

class Solution
{
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int x = edges[i][0], y = edges[i][1];
            if (!_union(x, y))
                return {x, y};
        }

        return {};
    }

private:
    int findRoot(int x)
    {
        if (x != parent[x])
        {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    bool _union(int x, int y)
    {
        int p1 = findRoot(x), p2 = findRoot(y);

        if (p1 == p2)
            return false;

        if (rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else if (rank[p1] < rank[p2])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p1] = p2;
            rank[p2]++;
        }

        return true;
    }
};