#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isWord = false;
};

class Solution
{
    unordered_set<string> res;
    vector<vector<bool>> visited;
    TrieNode root;

public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words)
    {
        for (const string &word : words)
        {
            addWord(word);
        }

        int ROWS = board.size(), COLS = board[0].size();
        visited.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r)
        {
            for (int c = 0; c < COLS; ++c)
            {
                dfs(board, r, c, &root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
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

    void dfs(vector<vector<char>> &board, int r, int c, TrieNode *node,
             string word)
    {
        int ROWS = board.size(), COLS = board[0].size();
        bool outOfBounds = r < 0 || c < 0 || r >= ROWS || c >= COLS;

        if (outOfBounds || visited[r][c] || node->children.count(board[r][c]) == 0)
            return;

        visited[r][c] = true;

        char currChar = board[r][c];
        node = node->children[currChar];
        word += currChar;

        if (node->isWord)
            res.insert(word);

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

            dfs(board, newR, newC, node, word);
        }

        visited[r][c] = false;
    }
};