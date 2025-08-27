# Word Search

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/word-search/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

Instead of searching character by character directly on the board, the solution builds a **Trie (prefix tree)** with the given word.
Then, it uses **DFS (Depth-First Search)** with backtracking to explore the board, checking if we can traverse the Trie nodes according to the letters found.

### **Code Breakdown**

#### 1. **TrieNode Class**

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};
```

- Each node stores children in a hashmap (`char -> TrieNode*`).
- `isWord` tells if the path from root to this node forms a complete word.

#### 2. **Solution Class Setup**

```cpp
class Solution {
    TrieNode root;
    vector<vector<bool>> visited;
```

- `root`: the root of the Trie.
- `visited`: matrix used to mark visited cells during DFS (to avoid reusing them).

#### 3. **exist function (main entry)**

```cpp
bool exist(vector<vector<char>> &board, string word) {
    addWord(word);  // put the word into the Trie
    int ROWS = board.size(), COLS = board[0].size();
    visited.assign(ROWS, vector<bool>(COLS, false));

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (dfs(board, r, c, &root)) // start DFS from each cell
                return true;
        }
    }
    return false;
}
```

- Build the Trie with the target word.
- Try to start a DFS search from **every position** in the board.
- If any DFS succeeds, return `true`.

#### 4. **addWord function**

```cpp
void addWord(const string &word) {
    TrieNode* curr = &root;
    for (char c : word) {
        if (curr->children.count(c) == 0) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
    }
    curr->isWord = true;
}
```

- Insert the word into the Trie.
- Each character becomes a new node if it doesn’t already exist.
- Mark the last character’s node as `isWord = true`.

#### 5. **dfs function**

```cpp
bool dfs(vector<vector<char>> &board, int r, int c, TrieNode *node) {
    int ROWS = board.size(), COLS = board[0].size();
    bool outOfBounds = c >= COLS || r >= ROWS || c < 0 || r < 0;

    // stop if out of bounds, already visited, or no child with this char
    if (outOfBounds || visited[r][c] ||
        node->children.count(board[r][c]) == 0)
        return false;

    visited[r][c] = true;

    char currChar = board[r][c];
    node = node->children[currChar]; // move to next Trie node

    // if we reached the end of the word
    if (node->isWord)
        return true;

    // explore neighbors
    int directions[4][2] = {
        {r + 1, c}, // down
        {r - 1, c}, // up
        {r, c + 1}, // right
        {r, c - 1}  // left
    };

    for (int i = 0; i < 4; i++) {
        int newR = directions[i][0];
        int newC = directions[i][1];
        if (dfs(board, newR, newC, node))
            return true;
    }

    // backtrack
    visited[r][c] = false;
    return false;
}
```

**What happens here:**

1. If position is invalid or already visited, stop.
2. If the current character is not in the Trie’s children, stop.
3. Mark cell as visited.
4. Move into the Trie node corresponding to this character.
5. If this Trie node marks the end of a word, return `true`.
6. Otherwise, explore all 4 neighbors (up, down, left, right).
7. If none works, backtrack → unmark the cell as visited.

## 🕒 Time and Space Complexity

- Time: O(N \* 4^L)
- Space:
  - Trie storage: O(L) for the word.
  - Visited matrix: O(N).
  - Recursion stack: O(L) in the worst case.

> where `N` = total cells, `L` = word length. Each cell could start a DFS, and each DFS can branch up to 4 directions.

## ✅ Solution

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Solution {
    TrieNode root;
    vector<vector<bool>> visited;

public:
    bool exist(vector<vector<char>>& board, string word) {
        addWord(word);

        int ROWS = board.size(), COLS = board[0].size();
        visited.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (dfs(board, r, c, &root))
                    return true;
            }
        }

        return false;
    }

private:
    void addWord(const string& word) {
        TrieNode* curr = &root;

        for (char c : word) {
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    };

    bool dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
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

        for (int i = 0; i < 4; i++) {
            int newR = directions[i][0];
            int newC = directions[i][1];

            if (dfs(board, newR, newC, node))
                return true;
        }

        visited[r][c] = false;

        return false;
    };
};
```
