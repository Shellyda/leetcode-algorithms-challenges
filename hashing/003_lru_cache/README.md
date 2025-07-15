# LRU Cache

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/lru-cache/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Uses a `hash map` for fast key access.
- Uses a `list` to track usage order (most recent at the front).

---

`get(key)`:

- If key doesn't exist, return `-1`.
- If it exists:

  - Move the key to the front (most recently used).
  - Return its value.

---

`put(key, value)`:

- If key exists, update value and move to front.
- If key doesn't exist and cache is full:

  - Remove the least recently used key (from the back).

- Insert the new key at the front.

## 🕒 Time and Space Complexity

- Time: O(1) for each `put()` and `get()` operation
- Space: O(n)

## ✅ Solution

```cpp
class LRUCache
{
private:
    int capacity;
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;

        order.erase(cache[key].second);
        order.push_front(key);
        cache[key].second = order.begin();
        return cache[key].first;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            order.erase(cache[key].second);
        }
        else if (cache.size() == capacity)
        {
            int lru = order.back();
            order.pop_back();
            cache.erase(lru);
        }

        order.push_front(key);
        cache[key] = {value, order.begin()};
    }
};
```
