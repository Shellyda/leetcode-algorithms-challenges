#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isWord = false;
};

class Solution
{
    TrieNode root;
    vector<vector<bool>> visited;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        addWord(word);

        int ROWS = board.size(), COLS = board[0].size();
        visited.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r)
        {
            for (int c = 0; c < COLS; ++c)
            {
                if (dfs(board, r, c, &root))
                    return true;
            }
        }

        return false;
    }

private:
    void addWord(const string &word)
    {
        TrieNode *curr = &root;

        for (char c : word)
        {
            if (curr->children.count(c) == 0)
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    };

    bool dfs(vector<vector<char>> &board, int r, int c, TrieNode *node)
    {
        int ROWS = board.size(), COLS = board[0].size();

        bool outOfBounds = c >= COLS || r >= ROWS || c < 0 || r < 0;

        if (outOfBounds || visited[r][c] ||
            node->children.count(board[r][c]) == 0)
            return false;

        visited[r][c] = true;

        char currChar = board[r][c];
        node = node->children[currChar];

        if (node->isWord)
            return true;

        int directions[4][2] = {
            {r + 1, c}, // down
            {r - 1, c}, // up
            {r, c + 1}, // right
            {r, c - 1}, // left
        };

        for (int i = 0; i < 4; i++)
        {
            int newR = directions[i][0];
            int newC = directions[i][1];

            if (dfs(board, newR, newC, node))
                return true;
        }

        visited[r][c] = false;

        return false;
    };
};