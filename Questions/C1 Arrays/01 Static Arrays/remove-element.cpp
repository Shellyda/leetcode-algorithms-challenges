
#include <iostream>
#include <vector>
using namespace std;

// Pseudocode
/*
left pointer = 0 -> l
Right pointer = 0 -> r

for r = 0 to length of nums
    if nums[r] != val
        nums[l] = nums[r]
        l++
*/
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int l = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] != val)
            {
                nums[l] = nums[r];
                l++;
            }
        }

        return l;
    }
};

// MAIN TO DEBUG
int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 4};

    int newLen = s.removeElement(nums, 1);

    for (int i = 0; i < newLen; i++)
    {
        cout << nums[i] << " ";
    }
}