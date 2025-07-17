# Top K Frequent Elements

- 🧩 Problem link: [Leetcode](hhttps://leetcode.com/problems/top-k-frequent-elements/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **Count Frequencies**:

   - Use a hash map (`unordered_map<int, int> count`) to count how many times each number appears in `nums`.

2. **Bucket Sort by Frequency**:

   - Create a vector of vectors `freq` where the index represents frequency.
   - For each `(num, frequency)` pair in `count`, add `num` to `freq[frequency]`.

3. **Collect Top K Elements**:

   - Iterate from the end of `freq` (highest frequency) to the beginning.
   - For each frequency bucket, add elements to the `results` vector.
   - Stop when `results.size() == k`.

4. **Return Result**:

   - Return the vector `results` containing the `k` most frequent elements.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums)
        {
            count[n]++;
        }

        for (const auto &pair : count)
        {
            freq[pair.second].push_back(pair.first);
        }

        vector<int> results;
        for (int i = freq.size() - 1; i > 0; --i)
        {
            for (int n : freq[i])
            {
                results.push_back(n);
                if (results.size() == k)
                    return results;
            }
        }

        return results;
    }
};
```
