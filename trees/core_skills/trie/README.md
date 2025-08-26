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

### Insert

To insert into the trie, we can iterate through each character of the word we wish to insert. If the character does not exist, we can insert it into our hashmap, along with its children. Otherwise, we can keep traversing down the tree. Once we have reached the last character, we can mark that TrieNode as a word.

> The visuals below represent the insertion process for words, "apple", "ape" and "nope". curr represents the current `TrieNode`, (in red circles) and `word`'s `boolean` value represents whether the word ends at a `TrieNode`.

**1. Insert "Apple"**
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/b41ba89e-efd5-4974-4a2d-d46d064e7600/sharpen=1)

**2. Insert "Ape"**
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/108ccf40-ecb2-4327-00ee-2ae7bb9c9600/sharpen=1)

**3. Insert "Nope"**
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/268e1ed6-342c-431f-0510-48dfc9b1ba00/sharpen=1)

### Search

We can search whether a word exists and return a boolean. To do this, we will iterate through each character and as soon as we encounter a character that is not in our tree, we can return false. This makes sense because a word cannot be complete if one of the characters is missing. However, it can also be the case that every single character exists but the last character is not marked as a word. For example, if our prefix tree has the word "apple" and we are looking for the word "app", even though the prefix exists, the word itself does not exist, because `p`'s `word` attribute is `false`.

**Search for word "No"**

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/9e22edaa-20c2-4413-ff5d-4fe279c11800/sharpen=1)

### Starts With

If we wanted to see if our tree contains a word given a prefix, we can use the following method. If each character of the prefix exists within our trie, we can return true. Otherwise, we will return false.

**Starts With Prefix "No"**

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/c33a86f8-c1fb-49eb-a1eb-59497a6f3700/sharpen=1)

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
