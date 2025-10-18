#include <vector>
using std::vector;

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<int>> pacific(ROWS, vector<int>(COLS, false));
        vector<vector<int>> atlantic(ROWS, vector<int>(COLS, false));
        vector<vector<int>> res;

        // DFS from all Pacific-bordering cells
        for (int c = 0; c < COLS; c++)
        {
            dfs(0, c, heights, pacific);         // Top edge (Pacific)
            dfs(ROWS - 1, c, heights, atlantic); // Bottom edge (Atlantic)
        }

        for (int r = 0; r < ROWS; r++)
        {
            dfs(r, 0, heights, pacific);         // Left edge (Pacific)
            dfs(r, COLS - 1, heights, atlantic); // Right edge (Atlantic)
        }

        // Cells reachable by both oceans
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (pacific[r][c] && atlantic[r][c])
                {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }

private:
    void dfs(int r, int c, vector<vector<int>> &heights,
             vector<vector<int>> &visited)
    {
        int ROWS = heights.size(), COLS = heights[0].size();
        visited[r][c] = true;

        int directions[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // down, up, right, left

        for (auto &dir : directions)
        {
            int newR = r + dir[0];
            int newC = c + dir[1];

            if (newR < 0 || newC < 0 || newR >= ROWS || newC >= COLS)
                continue;
            if (visited[newR][newC])
                continue;
            if (heights[newR][newC] < heights[r][c])
                continue; // must be >= to flow "up"

            dfs(newR, newC, heights, visited);
        }
    }
};
