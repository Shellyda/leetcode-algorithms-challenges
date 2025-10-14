#include <string>
using std::string;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;

        helper(0, count, s);
        helper(1, count, s);

        return count;
    }

    void helper(int rightStart, int &count, string &s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            int l = i, r = i + rightStart;

            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }
        }
    }
};