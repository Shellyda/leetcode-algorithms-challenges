#include <vector>
#include <map>
using std::map;
using std::vector;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
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
