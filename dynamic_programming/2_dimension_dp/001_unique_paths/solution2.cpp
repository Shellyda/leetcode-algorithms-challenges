#include <vector>
using std::vector;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        return dfs(0, 0, grid);
    }

private:
    int dfs(int r, int c, vector<vector<int>> &grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();

        if (r >= ROWS || c >= COLS)
            return 0;

        if (grid[r][c] > 0)
            return grid[r][c]; // cache

        if (r == ROWS - 1 && c == COLS - 1)
            return 1;

        int directions[2][2] = {{0, 1}, {1, 0}}; // right and down

        int total = 0;
        for (int i = 0; i < 2; i++)
        {
            int newR = r + directions[i][0];
            int newC = c + directions[i][1];

            total += dfs(newR, newC, grid);
        }

        grid[r][c] = total;

        return total;
    }
};
