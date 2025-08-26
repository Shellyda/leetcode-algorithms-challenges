# Implement Trie (Prefix Tree)

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/implement-trie-prefix-tree/description/)
- 🚦 Difficulty: 🟡 Medium

## Purpose

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the `trie`.
- `boolean search(String word)` Returns true if the string `word` is in the `trie` (i.e., was inserted before), and `false` otherwise.
- `boolean startsWith(String prefix)` Returns true if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

### Example 1:

```cpp
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]
```

### Explanation

```cpp
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
```

## Concept

Let's give some motivation behind why we need a trie.

Imagine we had a big box filled with different vegetables like cucumbers, cauliflower, tomatoes etc. If we wanted to organize them by their name, we would want to start by getting smaller boxes and label each one of the boxes with each letter of the alphabet. So all the vegetables that start with "A" will go into the box labelled "A", so on and so forth.

But, there are vegetables that share a first letter or even first few characters such as "cauliflower" and "cabbage". Instead of creating new boxes for every prefix, we can create new boxes inside our original box such that each new box is used to denote each additional letter in our vegetable's name.

So now that we have extra boxes inside of, say, "c" box, labelled with the second letter of each vegetable's name, we can now put "cauliflower" and "cabbage" in the same box and so on and so forth. We can keep doing this for each letter of the alphabet, until we have a bunch of smaller boxes inside bigger boxes.

- A trie allows us to organize words based on the first few characters (prefix). In the case of a trie, each vegetable box will be represented as a node and the edges are used to represent the characters that connect them.

- A trie, often referred to as a **prefix tree**, as that explains its purpose better, is a tree data structure that can be used to find words, given a prefix. It can do so in O(w) time, where w is the length of the word. This is because we only need to traverse the trie for each character in the word.

**We want to be able to insert, search, such that we have the following complexities:**

- Insert Word: O(w)
- Search Word: O(w)
- Search Prefix: O(w)

> The above operations are possible with a hashmap as well. But a hashmap will only support an exact match for a string, so in the worst case, it will take O(n) iterations to search for a prefix. A prefix tree will allow us to search for strings that start with specific prefix in O(w) time.

One real-world application of tries is **search auto-completion**. Autocomplete matches the prefix characters to predict the word or phrase you are going to type. And since searching a prefix is O(w), it is fast and efficient.

The visual below demonstrates a trie. Since there are 26 letters in the alphabet, each node will have at most 26 children. For the sake of brevity, we have used `...` to represent all the letters between c and z, exclusive.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/1cb7dc48-48a8-47be-c19f-3ffda3134800/sharpen=1)

## ✅ Solution

```cpp
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children; // hashmap: char -> node with chars of the word
    bool word = false; // mark if this char is the end of curr word
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
            if (curr->children.count(c) == 0) // if the char does not exists in root node like img above, add this char node
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c]; // change curr node to next char
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

        return curr->word; // if is a end of a word will return true
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
```
