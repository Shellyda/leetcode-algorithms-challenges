#include <vector>
using std::vector;

vector<int> performOperations(vector<int> arr, vector<vector<int>> operations)
{
    for (vector<int> curOp : operations)
    {
        int left = curOp[0], right = curOp[1];

        while (left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    return arr;
};