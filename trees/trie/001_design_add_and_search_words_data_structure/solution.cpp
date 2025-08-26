#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

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
