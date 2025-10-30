#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int r, int c)
{
    int ROWS = grid.size(), COLS = grid[0].size();

    if (r < 0 || c < 0 || r >= ROWS || c >= COLS)
        return;
    if (grid[r][c] == '#')
        return;

    grid[r][c] = '#';

    int directions[4][2] = {
        {0, -1}, // left
        {0, 1},  // right
        {1, 0},  // down
        {-1, 0}  // up
    };

    for (int i = 0; i < 4; i++)
    {
        int newR = r + directions[i][0];
        int newC = c + directions[i][1];

        dfs(grid, newR, newC);
    }
}

int main()
{
    int n, m, res = 0;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    string curr;
    for (int r = 0; r < n; r++)
    { // n
        cin >> curr;
        for (int c = 0; c < m; c++)
        {
            grid[r][c] = curr[c];
        }
    }

    for (int r = 0; r < n; r++)
    { // n
        for (int c = 0; c < m; c++)
        { // m
            if (grid[r][c] == '.')
            {
                dfs(grid, r, c);
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}
