# Design Disjoint Set (Union-Find)

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/unionFind)
- 🚦 Difficulty: 🟡 Medium

## Purpose

Design a Disjoint Set (aka Union-Find) class.

Your UnionFind class should support the following operations:

- `UnionFind(int n)` will initialize a disjoint set of size `n`.
- `int find(int x)` will return the root of the component that `x` belongs to.
- `bool isSameComponent(int x, int y)` will return whether `x` and `y` belong to the same component.
- `bool union(int x, int y)` will union the components that `x` and `y` belong to. If they are already in the same component, return `false`, otherwise return `true`.
- `int getNumComponents()` will return the number of components in the disjoint set.

### Example 1:

```cpp
Input:
["UnionFind", 10, "isSameComponent", 1, 3, "union", 1, 2, "union", 2, 3, "getNumComponents", "isSameComponent", 1, 3]

Output:
[null, 1, false, true, true, 8, true]
```

**Note:** The find method will not be directly tested, but you will need to use it in the implementation of the other methods. Thus, it will be tested indirectly.

## Concept

Union-Find is a useful tool for **keeping track of nodes connected in a graph and detecting cycles in a graph**. Of course, we can achieve this with DFS as well by using a hashset, however this is only efficient when there is a static graph. If we are adding edges overtime, that makes the graph dynamic, and Union-Find is a better choice.

### Disjoint sets

Union-Find operates on disjoint sets. Let's briefly go over them.

Disjoint sets are sets that don't have any element(s) in common. Formally, two disjoint sets are sets whose intersection is the empty set. Suppose we have two sets, `S1 = {1,2,3}` and `S2 = {4,5,6}`. `S1` and `S2` are referred to as disjoint sets, while two sets, `S3 = {1,2,5}`, and `S4 = {5,6,7}` are not disjoint.

Union-Find operates on disjoint sets. If we want to perform a union of two vertices, we need to ensure that those vertices belong to disjoint sets.

### Implementation

Suppose that we are given an array of edges, `edges: [1,2], [4,1], [2,4]`, which represents a graph. Here, each array in `edges` is an undirected, connected pair of vertices, i.e. `1` is connected to `2`.

Our task is to determine if this graph contains a cycle. We can solve this with Union-Find.

Union-Find is referred to as a "forest of trees". Initially, each vertex stands by itself, and for each vertex, we want to store the pointer to its parent. Since we have not connected them yet, each node is a parent to itself, i.e. points to itself.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/361f46bc-4999-4e55-65d1-85f114129600/sharpen=1)

Next, we go through the edges to connect the vertices. We start with the first edge, `[1,2]`.

Since `2` is connected to `1`, we can select it to be the child of 1. Here, it does not matter which vertex is the parent and which vertex is the child. However, this order starts to matter when the two components we are trying to union have different heights, also referred to as the rank.

The Union-Find data structure, has two operations. The Find operation and the Union operation. We want to ensure that we are not connecting vertices that are part of the same component. So, given a vertex, `n`, the find operation finds the parent of `n`. We can then use this in the union operation to join vertices together.

#### The initial setup

To implement Union-Find, we can have a `UnionFind` class. Within the constructor we can instantiate our `parent` hashmap and our rank hashmap. Alternatively, we can often use arrays to store the parents and ranks as well.

```cpp
class UnionFind {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    UnionFind(int n) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
};
```

#### Find

Our `find` function will accept a vertex `n` as an argument and return its root parent. We can use our parent hashmap where the key is the vertex and the value is the parent.

By traversing up the tree, we can find the root parent. If a vertex is a parent to itself, then it is the root parent.

If two vertices have the same root parent, then they are already apart of the same connected component. If they have different parents, they are part of different connected components.

**Path Compression**
As we are performing union on a large number of vertices, it can end up creating a pretty long chain, similar to a long linked list.

However, we can reduce the amount of these steps by traversing up two vertices at a time instead of one. This would mean that when we are going up the tree, we can set the parent of each node to be the root parent. This process is called path compression.

We can do this recursively.

```cpp
int find(int x) {
    // Finds the root of x
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
```

The line `self.parent[n] = self.find(self.parent[n])` is performing the path compression. It is updating the parent of the given vertex to point to the root parent.

#### Union

The union function takes two vertices and determines if a union can be performed.

1. If the two vertices share the same root parent, a union cannot be formed and we can return false.
2. If the two vertices, call them `n1` and `n2`, have parents `p1` and `p2` respectively, and `p1`'s rank is higher than `p2`, `p2` is the child to `p1`.
3. Conversely, `p1` is the child to `p2` if `p2`'s rank is higher than `p1`. If the rank/height of `p1` and `p2` are equal, we can set `p2` to be the parent of `p1` and increment the rank by `1`.

```cpp
bool union(int n1, int n2) {
    int p1 = find(n1), p2 = find(n2);
    if (p1 == p2) {
        return false;
    }

    if (rank[p1] > rank[p2]) {
        parent[p2] = p1;
    } else if (rank[p1] < rank[p2]) {
        parent[p1] = p2;
    } else {
        parent[p1] = p2;
        rank[p2] += 1;
    }
    return true;
}
```

The below visual demonstrates the find and the union function given` edges = [1,2], [4,1], [2,4]`. Notice that we connect `2` to `1`, then we connect `4` to `1` because `1` has a higher rank. But, when we reach `[2,4]`, `2`'s parent is `1` and `4`'s parent is also `1`, meaning they belong to the same connected component, i.e. there is a cycle.
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/3459bbfd-9b91-4eba-8467-917697776a00/sharpen=1)

## 🕒 Time and Space Complexity

In the naive case, the find function will result in `O(n)` because it is possible that the tree is just a chain like a linked list and we have to traverse every single node. By implementing union by rank and path compression, we get a time complexity of `α(n)`, where `α` is called the **Inverse Ackermann function**. It is assumed to be constant, `O(1)`, for nearly all input sizes. So, if `m` is the number of edges we have, then the time complexity of Union-Find is` O(m ∗ α(n))` which is assumed to be `O(m)`.

### Time and space complexity for solution below

- Time: O(n \* α(n))
- Space: O(n)

> Where `n` is the number of elements in the input and `\alpha(n)` is the **inverse Ackermann function**, which is nearly constant O(1)

## ✅ Solution

```cpp
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
```
