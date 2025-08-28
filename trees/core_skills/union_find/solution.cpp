#include <unordered_map>
using std::unordered_map;

class UnionFind
{
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int numComponents;

    UnionFind(int n)
    {
        numComponents = n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i; // set parent to be itself
            rank[i] = 0;   // height = 0
        }
    }

    int find(int x)
    {
        // finds the root of x
        if (x != parent[x])
        {
            parent[x] = find(parent[x]); // path compression -> map curr node to its grandparent
        }
        return parent[x];
    }

    bool isSameComponent(int x, int y)
    {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y)
    {
        if (isSameComponent(x, y))
            return false;

        int p1 = find(x), p2 = find(y);

        if (rank[p1] > rank[p2])
        {
            parent[p2] = p1; // p1 parent -> p2
        }
        else if (rank[p1] < rank[p2])
        {
            parent[p1] = p2; // p2 parent -> p1
        }
        else
        {                    // if p1 = p2, so choose one to be parent and up it rank by 1
            parent[p1] = p2; // p2 parent -> p1
            rank[p2]++;      // p2 rank + 1
        }
        numComponents--; // reduce the elements num by 1 after union
        return true;
    }

    int getNumComponents()
    {
        return numComponents;
    }
};
