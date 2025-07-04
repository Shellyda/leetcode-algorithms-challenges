# Number of students unable to eat lunch

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach - Solution 01

- Created a counter with `vector` and use it to get the frequency

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution 01 - Frequency Count

```cpp
int countStudents(vector<int> &students,vector<int> &sandwiches)
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
```

## 💡 Approach - Solution 02

- Use a queue to control the students frequency (intuitive way)

## 🕒 Time and Space Complexity

- Time: O(n^2)
- Space: O(1)

## ✅ Solution 02 - Queue

```cpp
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;

        for (int student : students) {
            q.push(student);
        }

        int res = n;
        for (int sandwich : sandwiches) {
            int cnt = 0;
            while (cnt < n && q.front() != sandwich) {
                q.push(q.front());
                q.pop();
                cnt++;
            }
            if (q.front() == sandwich) {
                q.pop();
                res--;
            } else {
                break;
            }
        }
        return res;
    }
```
