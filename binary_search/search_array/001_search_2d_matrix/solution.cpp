#include <vector>

using std::vector;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // loop all matrix -> O(n)
        // binSearch -> rows inside matrix -> O(logn)
        for (int i = 0; i < matrix.size(); i++)
        {
            if (binSearch(0, matrix[i].size() - 1, matrix[i], target) != -1)
                return true;
        }
        return false;
    }

    int binSearch(int l, int r, vector<int> &arr, int target)
    {
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);

            if (target > arr[mid])
            {
                l = mid + 1;
            }
            else if (target < arr[mid])
            {
                r = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
};
