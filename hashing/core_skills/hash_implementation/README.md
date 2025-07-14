# Hash Implementation - Design a Hash Table class

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/hashTable)
- 🚦 Difficulty: 🟡 Medium

Your `HashTable` class should support the following operations:

- `HashTable(int capacity)` will initialize an empty hash table with a capacity of `capacity`, where `capacity > 1`.
- `int get(int key)` will return the value associated with the `key`. If the `key` is not present in the hash table, return `-1`.
- `void insert(int key, int value)` will insert the key-value pair into the hash table. If the `key` is already present in the hash table, the original value should be replaced with the new value.
- `bool remove(int key)` will remove the key-value pair with the given key. If the key is not present, return `false`, otherwise return `true`
- `int getSize()` will return the number of keys in the hash table.
- `int getCapacity()` will return the capacity of the hash table.
- `void resize()` will double the capacity of the hash table. This method should be called automatically when the load factor reaches or exceeds `0.5`. Your `insert` method should automatically call `resize()` when necessary.

### Note:

You can choose how to handle collisions.

### Example 1:

```cpp
Input:
["HashTable", 4, "insert", 1, 2, "get", 1, "insert", 1, 3, "get", 1, "remove", 1, "get", 1]

Output:
[null, null, 2, 3, true, -1]
```

### Example 2:

```cpp
Input:
["HashTable", 2, "getCapacity", insert, 6, 7, "getCapacity", "insert", 1, 2, "getCapacity", "insert", 3, 4, "getCapacity", "getSize"]

Output:
[null, 2, null, 4, null, 8, null, 8, 3]
```
