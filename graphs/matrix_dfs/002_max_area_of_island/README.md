# Max Area of Island

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/max-area-of-island)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Using Depth First Search algorithm to get all adjacent land areas ("1") and count islands present in grid
- In each loop compare with the prev area value found and keep the bigger

## 🕒 Time and Space Complexity

- Time: O(m\*n)
- Space: O(m\*n)

> Where `m` is the number of rows and `n` is the number of columns in the `grid`

## ✅ Solution

```cpp
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int COLS = grid[0].size(), ROWS = grid.size();

        int area = 0;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    area = max(area, dfs(grid, r, c));
                }
            }
        }

        return area;
    }

private:
    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        if (r < 0 || c < 0 || c >= grid[0].size() || r >= grid.size() || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;

        int total = 1;

        total += dfs(grid, r + 1, c); // down
        total += dfs(grid, r - 1, c); // up
        total += dfs(grid, r, c + 1); // right
        total += dfs(grid, r, c - 1); // left

        return total;
    }
};
```
