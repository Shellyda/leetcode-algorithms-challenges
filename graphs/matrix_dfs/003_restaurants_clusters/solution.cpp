#include <vector>
using namespace std;

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