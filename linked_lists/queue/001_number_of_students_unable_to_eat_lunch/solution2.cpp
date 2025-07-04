#include <vector>
#include <queue>
using std::queue;
using std::vector;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        queue<int> q;

        for (int student : students)
        {
            q.push(student);
        }

        int res = n;
        for (int sandwich : sandwiches)
        {
            int cnt = 0;
            while (cnt < n && q.front() != sandwich)
            {
                q.push(q.front());
                q.pop();
                cnt++;
            }
            if (q.front() == sandwich)
            {
                q.pop();
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