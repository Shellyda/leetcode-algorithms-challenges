
#include <iostream>
#include <vector>
using namespace std;

// Pseudocode
/*
left pointer = 0 -> l
Right pointer = 1 -> r

for r = 1 to length of nums
    if nums[r-1] != nums[l]
        l++
        nums[l] = nums[i]
*/
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int left = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[left])
            {
                left++;
                nums[left] = nums[i];
            }
        }

        return left + 1;
    }
};

// MAIN TO DEBUG
int main()
{
    Solution s;
    vector<int> nums = {0, 1, 2};

    int newLen = s.removeDuplicates(nums);

    for (int i = 0; i < newLen; i++)
    {
        cout << nums[i] << " ";
    }
}