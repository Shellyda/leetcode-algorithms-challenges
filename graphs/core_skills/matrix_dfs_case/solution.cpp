#include <vector>
#include <algorithm>
using std::vector;

// Count paths (backtracking)
// In C++ it's easier to use a 2D array for visit rather than a hashset.
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
        if (grid[r][c] == 1 || visited[r][c])
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
