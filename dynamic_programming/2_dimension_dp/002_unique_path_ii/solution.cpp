#include <vector>
using std::vector;

class Solution
{
    vector<vector<int>> memo;

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        memo.resize(obstacleGrid.size(),
                    vector<int>(obstacleGrid[0].size(), 0));
        return dfs(0, 0, obstacleGrid);
    }

private:
    int dfs(int r, int c, vector<vector<int>> &grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();

        if (r >= ROWS || c >= COLS || grid[r][c])
            return 0;

        if (memo[r][c] > 0)
            return memo[r][c];

        if (r == ROWS - 1 && c == COLS - 1)
            return 1;

        int directions[2][2] = {{r + 1, c}, {r, c + 1}}; // down and right

        int total = 0;
        for (int i = 0; i < 2; i++)
        {
            int newR = directions[i][0], newC = directions[i][1];

            total += dfs(newR, newC, grid);
        }

        memo[r][c] = total;

        return total;
    }
};