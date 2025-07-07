# Matrix Breath-First Search

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/matrixBFS)
- 🚦 Difficulty: 🟡 Medium

## Purpose

You are given a binary matrix `Grid` where `0`s represent land and `1`s represent rocks that can not be traversed.

Return the length of the shortest path from the top-left corner of `Grid` to the bottom-right corner such that all traversed cells are land cells. You may only move vertically or horizontally through land cells.

### Note:

- If there is no such path, return `-1`.
- The length of a path is the number of moves from the starting cell to the ending cell.

### Example 1:

```cpp
Input: grid = [
  [0, 0, 0, 0],
  [1, 1, 0, 0],
  [0, 0, 0, 1],
  [0, 1, 0, 0]
]

Output:
6
```

## 🕒 Time and Space Complexity

- Time: O(m\*n)
- Space: O(m\*n)

## ✅ Solution

```cpp
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid)
    {
        int res = bfs(grid);

        return res < 0 ? -1 : res;
    }

private:
    int bfs(vector<vector<int>> &grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();

        vector<vector<int>> visited(4, vector<int>(4));
        queue<pair<int, int>> q;
        q.push(pair<int, int>(0, 0)); // avoid empty edge cases
        visited[0][0] = 1;

        int length = 0;

        while (!q.empty())
        {
            int queueLength = q.size();

            for (int i = 0; i < queueLength; i++)
            {
                pair<int, int> curPair = q.front();
                q.pop();

                int r = curPair.first, c = curPair.second;

                if (r == ROWS - 1 && c == COLS - 1)
                    return length;

                int directions[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};

                for (int j = 0; j < 4; j++)
                {
                    int newR = directions[j][0], newC = directions[j][1];

                    if (newR < 0 || newC < 0 || newR >= ROWS || newC >= COLS || visited[newR][newC] || grid[newR][newC])
                        continue;

                    q.push(pair<int, int>(newR, newC));
                    visited[newR][newC] = 1;
                }
            }
            length++;
        }
    }
};

```
