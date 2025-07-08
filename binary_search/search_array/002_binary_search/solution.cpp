#include <vector>

using std::vector;

int binarySearch(vector<int> arr, int target)
{
    int l = 0, r = arr.size() - 1;

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
