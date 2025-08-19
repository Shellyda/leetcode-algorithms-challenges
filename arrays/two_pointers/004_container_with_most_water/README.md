# Container with most water

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/container-with-most-water/submissions/1741101460/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. Start with `l` at the beginning and `r` at the end.
2. Compute area as `min(height[l], height[r]) * (r - l)`. The `min()` function directly addresses the "no slanting" constraint by ensuring the water level is capped by the shorter line.
3. Update the maximum area.
4. Move the pointer pointing to the **shorter line** (`l++` if `height[l] < height[r]`, else `r--`) because the area is limited by the smaller height.
5. Repeat until `l >= r`.

- Return the maximum area found.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, area = INT_MIN;

        while (l < r)
        {
            area = max(area, min(height[l], height[r]) * (r - l));

            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return area;
    }
};
```
