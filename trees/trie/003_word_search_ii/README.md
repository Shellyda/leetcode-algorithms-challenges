# Word Search II

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/word-search-ii/)
- 🚦 Difficulty: 🔴 Hard

## 💡 Approach

- Build a **Trie** that stores all words from the given list.
- Perform **DFS + backtracking** from every cell in the board.
- At each step:

  - Follow the path in the Trie.
  - If we reach a node marked as a word → save the word.

- Use a `visited` matrix to avoid reusing the same cell in one search.
- Use a `set` (`unordered_set`) to store results without duplicates.

**obs:**

- The Trie prunes invalid searches early.
  Example: if no word in the dictionary starts with `"zx"`, DFS stops immediately at `"z"`.
- Much faster than brute force checking every word for every path.

## **Code Breakdown**

### 1. **TrieNode Class**

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};
```

- Each TrieNode stores children (`char → TrieNode*`) and whether this node ends a word.

### 2. **Solution Class Setup**

```cpp
class Solution {
    unordered_set<string> res;       // stores found words (no duplicates)
    vector<vector<bool>> visited;    // visited cells during DFS
    TrieNode root;                   // root of Trie
```

- `res` ensures each found word is unique.
- `visited` prevents revisiting the same cell in one DFS path.
- `root` is the Trie root storing all words.

### 3. **Main Function: findWords**

```cpp
vector<string> findWords(vector<vector<char>> &board,
                         vector<string> &words)
{
    for (const string &word : words)
        addWord(word);  // insert every word into Trie

    int ROWS = board.size(), COLS = board[0].size();
    visited.assign(ROWS, vector<bool>(COLS, false));

    // Try DFS starting from each cell
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            dfs(board, r, c, &root, "");
        }
    }

    return vector<string>(res.begin(), res.end());
}
```

- Insert all dictionary words into the Trie.
- For each board cell, try to form words via DFS.
- At the end, return the result as a vector.

### 4. **Inserting Words: addWord**

```cpp
void addWord(const string &word) {
    TrieNode* curr = &root;
    for (char c : word) {
        if (curr->children.count(c) == 0)
            curr->children[c] = new TrieNode();
        curr = curr->children[c];
    }
    curr->isWord = true;  // mark word end
}
```

- Standard Trie insertion.
- At the last node of each word, mark it as `isWord = true`.

### 5. **DFS Search**

```cpp
void dfs(vector<vector<char>> &board, int r, int c,
         TrieNode *node, string word)
{
    int ROWS = board.size(), COLS = board[0].size();
    bool outOfBounds = r < 0 || c < 0 || r >= ROWS || c >= COLS;

    // invalid state: out of bounds, visited, or no valid Trie path
    if (outOfBounds || visited[r][c] ||
        node->children.count(board[r][c]) == 0)
        return;

    visited[r][c] = true;

    char currChar = board[r][c];
    node = node->children[currChar];
    word += currChar;

    // if this path forms a word, save it
    if (node->isWord)
        res.insert(word);

    // explore 4 directions
    int directions[4][2] = {
        {r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}
    };
    for (int i = 0; i < 4; i++) {
        int newR = directions[i][0];
        int newC = directions[i][1];
        dfs(board, newR, newC, node, word);
    }

    // backtrack
    visited[r][c] = false;
}
```

**Step by step inside DFS:**

1. Stop if out of bounds, already visited, or the current letter doesn’t exist in the Trie’s children.
2. Mark the cell as visited.
3. Move deeper in the Trie using the current board character.
4. Append the character to the `word` string.
5. If this Trie node is a valid word, store it in `res`.
6. Explore all four neighbors recursively.
7. Backtrack → unmark the cell as visited.

## 🕒 Time and Space Complexity

- Time: O(N \* 4^L)
- Space:
  - Trie size = `O(sum of all word lengths)`.
  - `visited` matrix = O(N).
  - Recursion stack = up to O(L).

> where `N` = number of board cells, `L` = maximum word length. But in practice, Trie pruning makes it much faster.

## ✅ Solution

```cpp
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
```
