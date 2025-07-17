#include <ctype.h>
#include <string>
using std::string;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.size() <= 1)
            return true;

        string filtered;

        for (char c : s)
        {
            if (isalnum(c))
            {
                filtered += tolower(c);
            }
        }

        int l = 0, r = filtered.size() - 1;

        while (l < r)
        {
            if (filtered[l] != filtered[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
};
