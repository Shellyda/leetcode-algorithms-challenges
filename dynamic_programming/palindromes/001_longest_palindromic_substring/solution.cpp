#include <string>
using std::string;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int length = 0, resIdx = 0;
        // odd sizes
        for (int i = 0; i < s.size(); i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                if (r - l + 1 > length)
                {
                    resIdx = l;
                    length = r - l + 1;
                }
                l--;
                r++;
            }
        }

        // even sizes
        for (int i = 0; i < s.size(); i++)
        {
            int l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                if (r - l + 1 > length)
                {
                    resIdx = l;
                    length = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(resIdx, length);
    }
};