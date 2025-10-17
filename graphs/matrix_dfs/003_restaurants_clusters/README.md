# Counting Restaurant Clusters

- 🧩 Problem link: Uber Tech Interview
- 🚦 Difficulty: 🟡 Medium

You are given an `m x n` grid, where each cell contains an integer representing the number of restaurants at that location. A cell with value `0` means there are no restaurants there.

Two or more restaurants belong to the **same cluster** if they are connected horizontally or vertically (not diagonally) through cells with a value greater than zero. A cluster is formed by a group of connected cells containing at least one restaurant.

**Task:**
Write a function that takes the grid as input and returns the total number of restaurant clusters.

**Examples:**

1. **Input:**

```
0 0 0 1
0 2 3 1
0 0 0 0
```

**Output:**

```
1
```

2. **Input:**

```
1 0 0 1
0 2 3 1
0 0 0 0
```

**Output:**

```
2
```

**Notes:**

- Only cells with a value greater than zero can form clusters.
- Connections are considered only horizontally and vertically.

## 💡 Approach

1. **Idea:**

- A cluster is a group of connected cells with a value > 0 (restaurants), connected horizontally or vertically.
- Each time we find a non-zero cell, it starts a new cluster.
- DFS explores the entire cluster, marking visited cells as 0 to avoid double counting.

2. **Algorithm:**

- Traverse every cell in the grid.
- If `grid[r][c] > 0`, call `dfs(r, c, grid)` and increment the cluster counter.
- In DFS:

  - Stop if out of bounds or cell is 0.
  - Mark the cell as visited (`grid[r][c] = 0`).
  - Recursively visit all 4 neighbors (up, down, left, right).

3. **Why it works:**

- Each DFS explores all connected restaurants of a cluster.
- Marking cells ensures each cluster is counted only once.

## 🕒 Time and Space Complexity

- Time: O(n \* m) — each cell visited at most once.
- Space: O(n \* m) — recursion stack in worst case.

## ✅ Solution

```cpp
class Solution
{
public:
    int numberOfRestaurantClusters(vector<vector<int>> &grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();
        int clusters = 0;

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] != 0)
                {
                    dfs(r, c, grid);
                    clusters++;
                }
            }
        }

        return clusters;
    }

    void dfs(int r, int c, vector<vector<int>> &grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();

        // out of bounds
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS)
            return;

        if (grid[r][c] == 0)
            return;

        grid[r][c] = 0;

        int directions[4][2] = {
            {0, 1},  // right
            {0, -1}, // left
            {1, 0},  // up
            {-1, 0}, // down
        };

        for (int i = 0; i < 4; i++)
        {
            int newR = r + directions[i][0];
            int newC = c + directions[i][1];

            dfs(newR, newC, grid);
        }
    }
};
```
