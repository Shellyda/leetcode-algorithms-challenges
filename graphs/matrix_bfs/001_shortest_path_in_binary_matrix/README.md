# Shortest Path in Binary Matrix

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Create one array with all 8 directions ways we can move
- Use bfs going for each direction case and mark as visited

## 🕒 Time and Space Complexity

- Time: O(n^2)
- Space: O(n^2)

## ✅ Solution

```cpp
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        return bfs(grid);
    }

private:
    int bfs(vector<vector<int>> &grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();

        if (grid[0][0] != 0 || grid[ROWS - 1][COLS - 1] != 0)
            return -1;

        vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = 1;

        int length = 1;

        int directions[8][2] = {
            {0, 1},   // right
            {0, -1},  // left
            {1, 0},   // down
            {-1, 0},  // up
            {1, 1},   // diagonal down-right
            {-1, -1}, // diagonal up-left
            {1, -1},  // diagonal down-left
            {-1, 1}   // diagonal up-right
        };

        while (!q.empty())
        {
            int queueLen = q.size();

            for (int i = 0; i < queueLen; i++)
            {
                auto [r, c] = q.front();
                q.pop();

                if (r == ROWS - 1 && c == COLS - 1)
                    return length;

                for (int j = 0; j < 8; j++)
                {
                    int newR = r + directions[j][0];
                    int newC = c + directions[j][1];

                    // check if its not out of bounds or its visited
                    if (newR >= 0 && newR < ROWS && newC >= 0 && newC < COLS &&
                        grid[newR][newC] == 0 && visited[newR][newC] == 0)
                    {
                        visited[newR][newC] = 1;
                        q.push({newR, newC});
                    }
                }
            }
            length++;
        }

        return -1;
    }
};
```
