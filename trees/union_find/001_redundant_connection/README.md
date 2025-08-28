# Redundant Connection

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/redundant-connection/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

**Key intuition**:
Use Union-Find to dynamically connect nodes. The first edge that tries to connect two nodes already in the same set is the one creating a cycle → the redundant edge.

1. **Initialization**

   - Each node is its own parent (`parent[i] = i`) and has rank 0.
   - This sets up the **Union-Find structure** for cycle detection.

2. **Processing edges**

   - For each edge `(x, y)`:

     - Try to union the two nodes.
     - If they already have the same root, then connecting them would form a **cycle**.
     - That edge is the redundant connection → return it.

3. **Union operation**

   - Find the root of each node with **path compression** (makes future lookups faster).
   - If roots are different, merge them based on **rank** (attach the smaller tree under the larger one).
   - If roots are the same, the union fails → meaning the edge is redundant.

## 🕒 Time and Space Complexity

- Time: O(n \* α(n))
- Space: O(n)

> Where `n` is the number of elements in the input and `\alpha(n)` is the **inverse Ackermann function**, which is nearly constant O(1)

## ✅ Solution

```cpp
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
            parent[x] = findRoot(parent[x]); // path compression
        }
        return parent[x];
    }

    bool _union(int x, int y) // union by rank (height)
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
```
