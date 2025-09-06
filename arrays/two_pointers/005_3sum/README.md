# 3Sum

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/3sum/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

Using sorting and the two-pointer technique:

1. **Sort the array** so that we can efficiently move pointers and handle duplicates.
2. **Fix one number** (`nums[i]`) at a time.
3. Use two pointers (`l` and `r`) to find pairs whose sum equals `-nums[i]`.

   - If the sum is zero, we record the triplet.
   - If the sum is less than zero, we move `l` forward to increase it.
   - If the sum is greater than zero, we move `r` backward to decrease it.

4. To avoid duplicates, we store results in a `set<vector<int>>`.

Finally, we convert the set into a vector and return the unique triplets.

## 🕒 Time and Space Complexity

- Time: O(n^2)
- Space:
  - O(1) or O(n) extra space depending on the sorting algorithm
  - O(m) space for the output list

## ✅ Solution

```cpp
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> triplets;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;

            while (l < r)
            {
                int currSum = nums[i] + nums[l] + nums[r];

                if (currSum == 0)
                {
                    triplets.insert({nums[i], nums[l], nums[r]});
                    l++;
                }
                else if (currSum < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }

        for (auto vec : triplets)
            res.push_back(vec);

        return res;
    }
};
```
