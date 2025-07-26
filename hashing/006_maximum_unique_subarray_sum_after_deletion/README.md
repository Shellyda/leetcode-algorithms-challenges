# Maximum Unique Subarray Sum After Deletion

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. **Initialize**:

   * `unordered_set<int> set` — to track unique elements.
   * `sum = 0` — total sum of unique **positive** integers.
   * `negative = INT_MIN` — keeps track of the **largest negative** number seen.

2. **Iterate through `nums`**:

   * If `n` is **not in the set**:

     * Add `n` to the set.
     * If `n <= 0` → update `negative` with `max(negative, n)`.
     * If `n > 0` → add to `sum`.

3. **Return result**:

   * If **no positive numbers were added** (i.e. `sum == 0`) and there were negative numbers → return `negative`.
   * Otherwise → return `sum`.

### **Edge Case Handling**

* Handles **duplicates** using the set.
* Handles **all-negative arrays** by returning the **least negative** value instead of 0.

## 🕒 Time and Space Complexity
- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> set;

        int sum = 0, negative = INT_MIN;

        for (int n : nums) {
            if (!set.count(n)) {
                set.insert(n);
                if (n <= 0) {
                    negative = max(negative, n);
                } else {
                    sum += n;
                }
            }
        }

        return negative != INT_MIN && sum == 0 ? negative : sum;
    }
};
```
