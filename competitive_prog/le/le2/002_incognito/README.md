# Incognito

- 🧩 Problem link: [BAPC 2013](https://vjudge.net/contest/752293#problem/B)
- 🚦 Difficulty: B

## Description

Spies use attributes to disguise themselves to avoid being recognized.  
For example, when putting on sunglasses, a spy suddenly looks completely different.  
Every combination of attributes gives a different appearance, but not all combinations are possible.  
For instance, a **hat** and a **turban** are both _headgear_ and cannot be used at the same time.

Given the list of available attributes, compute how many **distinct disguises** can be made.

### Input

- The first line contains a positive integer: the number of test cases (at most 100).
- After that, for each test case:
  - One line with an integer `n` (0 ≤ n ≤ 30): the number of available attributes.
  - Then `n` lines follow, each containing two space-separated strings: the **name** and the **category** of the attribute.

#### Notes:

- All strings consist of at least 1 and at most 20 lowercase letters.
- Within a test case, all names are distinct.

### Output

For each test case, print one line with an integer:  
the number of possible distinct disguises that can be made with the given attributes,  
such that **at most one attribute from each category** is used.

### Example

**Input:**

```
2
3
hat headgear
sunglasses eyewear
turban headgear
3
mask face
sunglasses face
makeup face
```

**Output:**

```
5
3
```
