#include <vector>
#include <algorithm>
using std::max;
using std::vector;

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
