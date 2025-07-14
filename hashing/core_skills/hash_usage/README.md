# Hash Usage

Hash maps are probably one of the most useful data structures/concepts for coding interviews. When questions use the words "unique", "count", or "frequency", it is almost certain a hashmap or hashset will be useful for solving the problem.

> Recall that the difference between a set and a map is that in sets contain keys only, while maps contain key-value pairs.

## Motivation

**Let's start off by comparing hash maps to tree maps and sorted arrays and understand what trade-offs we make using each data structure.**

| **Operation**         | **TreeMap**        | **HashMap** | **Array**                     |
| --------------------- | ------------------ | ----------- | ----------------------------- |
| **Insert**            | **_O_(*log* *n*)** | **_O_(1)**  | **_O_(_n_)**                  |
| **Remove**            | **_O_(*log* *n*)** | **_O_(1)**  | **_O_(_n_)**                  |
| **Search**            | **_O_(*log* *n*)** | **_O_(1)**  | **_O_(*log* *n*), if sorted** |
| **Inorder Traversal** | **O(n)**           | **-**       | **-**                         |

![image.png](attachment:e9ba2d6f-3d72-4f5d-9455-6b24c732d9b8:image.png)

> The time complexity listed in the table for hash maps is the average case time complexity. However, it is widely accepted in most cases, including interviews, to assume constant time complexity.

## Tree Maps vs Hash Maps

**The downside of hash maps is that they are not ordered**, so it not possible to traverse the keys of a hashmap in any particular order. If you were to iterate through all the keys, you would first need to sort them, which will run in *O*(*n* *log* *n*) time, making it slower than an in order traversal of a tree map which is *O*(_n_).

Because hashmaps don't allow duplicates and have key-value pairs, we can use them to count frequency of keys. Going back to our phonebook example, we can count the number of times a given name appears in our phonebook by mapping the name to its frequency.

Given the array below, we can add all the elements into a hash map as keys. Because hash maps do not allow duplicates, we can use this to our advantage. If a name already exists in our hash map as the key and we encounter it again in our array, we can just increment its value by 1. If the name does not exist, we can add it to our hash map and set the frequency to 1.

**`["alice", "brad", "collin", "brad", "dylan", "kim"]`**

| **Key**    | **Value** |
| ---------- | --------- |
| **Alice**  | **1**     |
| **Brad**   | **2**     |
| **Collin** | **1**     |
| **Dylan**  | **1**     |
| **Kim**    | **1**     |

**The following code demonstrates how the above operation will execute.**

```cpp
vector<string> names = {"alice", "brad", "collin", "brad", "dylan", "kim"};
unordered_map<string, int> countMap;

for (string& name: names) {
    if (countMap.count(name) == 0) {
        countMap[name] = 1;
    } else {
        countMap[name]++;
    }
}
```

## Time and Space Complexity

### Time

The above counting algorithm, when implemented using a hash map, is more efficient than using a tree map. With a tree map, the insertion operation would cost *O*(*log* *n*) time and if n*n* is the size of the array, it would total to *O*(*n* *log* *n*) time.

**With a hashmap, this costs *O*(_n_).**

### Space

The space consumed by a hash map is *O*(_n_), where *n* is proportional to the number of unique keys in the array.
