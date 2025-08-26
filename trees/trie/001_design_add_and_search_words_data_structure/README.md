# Design Add and Search Words Data Structure

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

We use a **Trie (prefix tree)** to store all the words. A Trie node keeps:

- a map from characters to child nodes
- a flag `word` that marks the end of a word

**Adding a word**

- Start from the root.
- For each character `c` in the word:

  - If `c` is not already a child, create a new Trie node.
  - Move to that child.

- After processing all characters, mark the current node as the end of a word (`word = true`).

This way, each word is stored character by character in the tree.

> The visuals below represent the insertion process for words, "apple", "ape" and "nope". curr represents the current `TrieNode`, (in red circles) and `word`'s `boolean` value represents whether the word ends at a `TrieNode`.

**1. Insert "Apple"**
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/b41ba89e-efd5-4974-4a2d-d46d064e7600/sharpen=1)

**2. Insert "Ape"**
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/108ccf40-ecb2-4327-00ee-2ae7bb9c9600/sharpen=1)

**3. Insert "Nope"**
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/268e1ed6-342c-431f-0510-48dfc9b1ba00/sharpen=1)

**Searching a word**

We use **DFS recursion** because of the `'.'` wildcard.

- Start at the root and process each character in the search string.
- If the current character is a **normal letter**:

  - Check if it exists in the current node’s children.
  - If not, return false.
  - Otherwise, move to that child and continue.
    ![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/9e22edaa-20c2-4413-ff5d-4fe279c11800/sharpen=1)

- If the current character is a **dot (`'.'`)**:

  - It means "any character".
  - We must explore _all children_ of the current node recursively.
  - If at least one recursive call returns true, the whole search is true.

- When we reach the end of the search string, we return whether the current node is marked as a complete word.

## 🕒 Time and Space Complexity

- **Add word:**

  - Time: `O(L)` where `L` = length of the word.
  - Space: up to `O(L)` new nodes (if no prefix exists).

- **Search word:**

  - Best case (no dots): `O(L)` because we just follow the path.
  - Worst case (with many dots): could branch into multiple children, up to `O(26^L)` in the absolute worst case, but usually much smaller because the Trie limits branching.

## ✅ Solution

```cpp
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool word = false;
};

class WordDictionary
{
public:
    TrieNode root;

    void addWord(string word)
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
        curr->word = true;
    }

    bool search(string word) { return dfs(word, 0, &root); }

private:
    bool dfs(string &word, int i, TrieNode *node)
    {
        if (i == word.size())
            return node->word;

        char c = word[i];
        if (c == '.')
        {
            for (auto &[ch, child] : node->children)
            {
                if (dfs(word, i + 1, child))
                    return true;
            }
            return false;
        }
        else
        {
            if (node->children.count(c) == 0)
                return false;
            return dfs(word, i + 1, node->children[c]);
        }
    }
};
```
