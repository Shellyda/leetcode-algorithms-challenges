#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hashMap;

        for (const auto &s : strs)
        {                             // ['nat', 'tat']
            vector<int> count(26, 0); // a...z

            for (char c : s)
            { // map 'a' to index 0, map 'b' to index 1.... map 'z' to index 26
                // c -> 'n' - 'a' values
                count[c - 'a']++;
            }

            /*
              a -> 80, 80 - 80 = 0
              b -> 81, 81 - 80 = 1
              ...
            */

            // setting key to count letters pattern
            string key = to_string(count[0]);

            for (int i = 1; i < 26; ++i)
            {
                key += ',' + to_string(count[i]);
                // 1
                // 1, 0, 1
                // 1, 0, 1, 0
                //...
            }

            hashMap[key].push_back(s);
        }

        vector<vector<string>> res;

        for (const auto &pair : hashMap)
        {

            res.push_back(pair.second);
        }

        return res;
    }
};
