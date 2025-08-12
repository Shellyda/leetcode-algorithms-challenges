#include <vector>
#include <string>
#include <algorithm>
using std::max;
using std::string;
using std::vector;

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int l = 0, r = 1, maxLen = 1;

        string prevSign = "";

        while (r < arr.size())
        {
            int currLen = r - l + 1;
            if (arr[r - 1] > arr[r] && prevSign != ">")
            {
                maxLen = max(maxLen, currLen);
                r++;
                prevSign = ">";
            }
            else if (arr[r - 1] < arr[r] && prevSign != "<")
            {
                maxLen = max(maxLen, currLen);
                r++;
                prevSign = "<";
            }
            else
            {
                r = arr[r - 1] == arr[r]
                        ? r + 1 // Jump - get out of subarray because equal sign
                        : r;
                l = r - 1; // Move left pointer to be behind r pointer and start
                           // new subarray
                prevSign = "";
            }
        }
        return maxLen;
    }
};