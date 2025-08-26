#include <unordered_map>
#include <string>
using std::string;
using std::unordered_map;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool word = false;
};

class Trie
{
public:
    TrieNode root;

    void insert(string word)
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

    bool search(string word)
    {
        TrieNode *curr = &root;
        for (char c : word)
        {
            if (curr->children.count(c) == 0)
                return false;
            curr = curr->children[c];
        }

        return curr->word;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = &root;
        for (char c : prefix)
        {
            if (curr->children.count(c) == 0)
                return false;
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */