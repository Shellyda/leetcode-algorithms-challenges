# Matrix Depth-First Search

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/matrixDFS)
- 🚦 Difficulty: 🟡 Medium

## Purpose

You are given a binary matrix `Grid` where `0`s represent land and `1`s represent rocks that can not be traversed.

Return the number of unique paths from the top-left corner of `Grid` to the bottom-right corner such that all traversed cells are land cells. You may only move vertically or horizontally through land cells. For an individual unique path you cannot visit the same cell twice.

## 🕒 Time and Space Complexity

- Time: O(numColumns^(n\*m))
- Space: O(numColumns^(n\*m))

## ✅ Solution

```cpp
class Solution
{
public:
    int countPaths(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // special case -> begin and end are rocks
        if (grid[0][0] || grid[rows - 1][cols - 1])
            return 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        return dfs(grid, 0, 0, visited);
    }

private:
    int dfs(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &visited)
    {
        int rows = grid.size(), cols = grid[0].size();

        // Out of bounds
        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return 0;

        // invalid point or visited
        if (grid[r][c] || visited[r][c])
            return 0;

        // found one path
        if (r == rows - 1 && c == cols - 1)
            return 1;

        visited[r][c] = true;

        int total = 0;
        total += dfs(grid, r + 1, c, visited); // down
        total += dfs(grid, r - 1, c, visited); // up
        total += dfs(grid, r, c + 1, visited); // right
        total += dfs(grid, r, c - 1, visited); // left

        visited[r][c] = false; // backtrack

        return total;
    }
};
```
