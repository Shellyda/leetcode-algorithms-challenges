#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string encoded;
        for (string &str : strs)
        {
            encoded += to_string(str.size()) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        int i = 0;

        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
                j++;

            int len = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }

        return result;
    }
};
