#include <vector>
#include <queue>
#include <utility>
using std::pair;
using std::queue;
using std::vector;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        return bfs(grid);
    }

private:
    int bfs(vector<vector<int>> &grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int, int>> q;

        int minutes = 0, freshCount = 0;

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    freshCount++;
                }
                if (grid[r][c] == 2)
                {
                    q.push({r, c});
                }
            }
        }

        int directions[4][2] = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (freshCount > 0 && !q.empty())
        {
            int queueLen = q.size();
            for (int i = 0; i < queueLen; i++)
            {
                auto [r, c] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++)
                {
                    int newR = r + directions[j][0];
                    int newC = c + directions[j][1];

                    if (newR >= 0 && newC >= 0 && newR < ROWS && newC < COLS && grid[newR][newC] == 1)
                    {
                        grid[newR][newC] = 2;
                        q.push({newR, newC});
                        freshCount--;
                    }
                }
            }

            minutes++;
        }

        return freshCount == 0 ? minutes : -1;
    }
};
