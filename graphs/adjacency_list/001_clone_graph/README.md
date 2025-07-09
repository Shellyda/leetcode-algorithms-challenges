# Clone Graph

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/clone-graph)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Use DFS and HashMap structure and clone all graph as all nodes are connected (undirected graph)

## 🕒 Time and Space Complexity

- Time: O(V + E)
- Space: O(V)

> Where `V` is the number of vertices and `E` is the number of edges.

## ✅ Solution

```cpp
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        map<Node *, Node *> oldToNew; // map the copies
        return dfs(node, oldToNew);
    }

private:
    Node *dfs(Node *node, map<Node *, Node *> &oldToNew)
    {
        if (!node) // if is null
            return nullptr;

        if (oldToNew.count(node)) // check if exist already in hashMap
            return oldToNew[node];

        Node *copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node *neighbor : node->neighbors)
        {
            copy->neighbors.push_back(dfs(neighbor, oldToNew)); // map all neighbors
        }

        return copy;
    }
};
```
