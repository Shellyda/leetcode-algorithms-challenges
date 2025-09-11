# Formats of Graphs

**A graph can be represented in different ways. It is an abstract concept that is made concrete using different data structures. Most commonly, graphs are represented using the following:**

- Matrix
- Adjacency Matrix
- Adjacency List

### Matrix

A matrix is a two-dimensional array with rows and columns, and a graph can be represented using a matrix. In the code below, each array, separated by commas, represents each row. Here we have four rows and four columns. Everything is indexed by 0 and the idea is that we should be able to access an arbitrary element given a specified row and column. Accessing the second row can simply be done by `grid[1]` and accessing the first column in the second row may be done by `grid[1][0]`.

```cpp
// Matrix (2D Grid)
int grid[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {0, 1, 0, 0}
};
```

How can this be used to represent a graph? As we mentioned, graphs are abstract and can be defined in many ways. Let's say that all of the `0`'s in our grid are vertices. To traverse a graph, we are allowed to move up, down, left and right. If we are to connect the `0`s together, using our edges, we would end up getting a bunch of connected zeroes, which are connected components, and that denotes a graph.

![hello](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/f3c04f37-7656-4836-f263-3ae19258c100/sharpen=1)

**The space complexity of a matrix is *O*(*n*∗*m*) where n*n* is the number of rows and m*m* is the number of columns.**

### Adjacency Matrix

**This is a less common input format. Here, the index of the array represents a vertex itself. Let's take an example:**

```cpp
// Adjacency matrix
int adjMatrix[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {0, 1, 0, 0}
};
```

**Because the indices themselves represent a vertex**

- 0 denotes that an edge does not exist between a given `v1, v2` pair, where `v1` is the row and `v2` is the column.
- 11 denotes that there does exist an edge between a given `v1, v2` pair.

For example, `adjMatrix[1][2] == 0` means there is no edge between vertex `1` and `2`. Also, `adjMatrix[2][1] == 0` means there is no edge between vertex `2` and `1`. Keep in mind the edges are directed. We can conclude the following from this:

```cpp
// an edge exists from v1 to v2
adjMatrix[v1][v2] = 1;

// an edge exists from v2 to v1
adjMatrix[v2][v1] = 1;

// No edge exists from v1 to v2
adjMatrix[v1][v2] = 0;

// No edge exists from v2 to v1
adjMatrix[v2][v1] = 0;
```

**To actualize the above adjacency matrix, we can look at the following visual.**

![hello](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/02f2aedd-88d5-461d-9fdd-0bffc2e81400/sharpen=1)

**The issue with this is that if our graph has few edges it is not a good use of memory. Because it is a square matrix, the space complexity is *O*(*V^*2), where V is the number of vertices.**

### **Adjacency List**

These are typically the most common way of representing graphs. This can also be implemented with a 2-D array, but often times is alternatively implemented with a hashmap. The convenience here is that we can declare it using a class called `GraphNode` and it contains a list attribute called `neighbors`, using which we can access all of a given vertex's neighbor.

```cpp
class GraphNode {
public:
    int val_;
    vector<int> neighbors_;

    GraphNode(int val) {
        val_ = val;
    }
};
```

This ends up being more space efficient compared to an adjacency matrix because we only store the edges that actually exist. **The space complexity is O(V+E), where V is the number of vertices and E is the number of edges.**

![hello](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/85b20b68-357a-4a6d-7c7a-e09256693200/sharpen=1)
