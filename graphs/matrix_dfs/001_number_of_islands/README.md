# Number of Islands

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/number-of-islands)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Using Depth First Search algorithm to get all adjacent land areas ("1") check

## 🕒 Time and Space Complexity

- Time: O(m\*n)
- Space: O(m\*n)

> Where `m` is the number of rows and `n` is the number of columns in the `grid`

## ✅ Solution

```cpp
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '1')
                {
                    dfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }

private:
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        int rows = grid.size(), cols = grid[0].size();

        // went out of bounds or its water
        if (r < 0 || c < 0 || c >= cols || r >= rows || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        dfs(grid, r + 1, c); // up
        dfs(grid, r - 1, c); // down
        dfs(grid, r, c + 1); // right
        dfs(grid, r, c - 1); // left
    }
};
```
