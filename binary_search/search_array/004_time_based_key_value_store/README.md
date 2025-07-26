# Time Based key Value Store

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/time-based-key-value-store/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **Data structure**:

   - `unordered_map<string, vector<pair<int, string>>> keyStore`
   - For each `key`, we store a list of `(timestamp, value)` pairs, in increasing order of timestamp.

2. **set(key, value, timestamp)**:

   - Simply appends `{timestamp, value}` to the vector for that `key`.

3. **get(key, timestamp)**:

   - Performs **binary search** on the list of pairs for that `key`.
   - Goal: Find the **largest timestamp ≤ given timestamp**.
   - If found, store `result = value` and search to the **right** to find a larger valid timestamp.
   - If not found, return `""`.

## 🕒 Time and Space Complexity

- Time: O(1) for `set()` and O(logn) for `get()`
- Space: O(m\*n)

> Where `n` is the total number of values associated with a key and `m` is the total number of keys

## ✅ Solution

```cpp
class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> keyStore;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        keyStore[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        auto &timeline = keyStore[key];
        int left = 0, right = timeline.size() - 1;
        string result = "";

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (timeline[mid].first <= timestamp)
            {
                result = timeline[mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};
```
