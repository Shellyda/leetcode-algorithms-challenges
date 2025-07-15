#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> groups;
        for (int i = 0; i < strs.size(); i++)
        {
            int left = i, right = strs.size() - 1;
            vector<string> subList;
            subList.push_back(strs[left]);
            while (left < right)
            {
                if (areAnagrams(strs[left], strs[right]))
                {
                    subList.push_back(strs[right]);
                    strs.erase(strs.begin() + right);
                }

                right--;
            }
            groups.push_back(subList);
        }

        return groups;
    }

private:
    bool areAnagrams(string str1, string str2)
    {
        if (str1.size() != str2.size())
            return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (int i = 0; i < str1.size(); i++)
        {
            map1[str1[i]]++;
            map2[str2[i]]++;
        }

        return map1 == map2;
    }
};
