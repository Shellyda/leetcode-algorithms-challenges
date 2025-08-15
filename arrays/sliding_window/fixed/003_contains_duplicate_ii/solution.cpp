#include <unordered_set>
#include <vector>
using namespace std;

// Check if array contains a pair of duplicate values,
// where the two duplicates are no farther than k positions from
// eachother (i.e. arr[i] == arr[j] and abs(i - j) + 1 <= k).
bool closeDuplicatesBruteForce(vector<int> &nums, int k)
{
    int size = static_cast<int>(nums.size());
    for (int L = 0; L < size; L++)
    {
        for (int R = L + 1; R < min(size, L + k); R++)
        {
            if (nums[L] == nums[R])
            {
                return true;
            }
        }
    }
    return false;
}