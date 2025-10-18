# Pacific Atlantic Water Flow

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/pacific-atlantic-water-flow/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

Instead of starting from every cell and going **toward** the oceans,
start **from the oceans** and move **inward**, marking which cells can be reached by each ocean.

1. Create two boolean matrices:

   - `pacific[r][c]` — cells reachable **from the Pacific**.
   - `atlantic[r][c]` — cells reachable **from the Atlantic**.

2. Perform DFS/BFS **from the ocean-border cells**:

   - Pacific → top row (0, c) and left column (r, 0).
   - Atlantic → bottom row (ROWS-1, c) and right column (r, COLS-1).

3. During DFS, move only to cells with **equal or greater height**,
   simulating the reverse of water flow (“climbing up” the terrain).

4. Finally, iterate over all cells and collect those that are `true` in both matrices.

```text
for each cell on Pacific border:
    dfs(cell, pacific)

for each cell on Atlantic border:
    dfs(cell, atlantic)

for each cell in grid:
    if pacific[r][c] and atlantic[r][c]:
        add (r, c) to result
```

## 🕒 Time and Space Complexity

- Time: O(m × n)
  Each cell is visited at most twice (once for each ocean’s DFS).

- Space: O(m × n)
  For the two `visited` matrices and recursion stack.

## ✅ Solution

```cpp
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
```
