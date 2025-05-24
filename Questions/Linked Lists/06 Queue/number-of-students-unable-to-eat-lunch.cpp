#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int res = students.size();
        vector<int> cnt(2); // Dynamic Array initialized with two elements, by default both with 0 value
        for (int &student : students)
        {
            cnt[student]++; // counting students 0 and 1 frequency
        }

        for (int &s : sandwiches)
        {
            if (cnt[s] > 0)
            { // if still have students for top sandwiches
                cnt[s]--;
                res--;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};