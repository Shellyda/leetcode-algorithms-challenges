# Course Schedule

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/course-schedule/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Cycle detection with DFS

## 🕒 Time and Space Complexity

- Time: O(V + E)
- Space: O(V + E)

> Where the `V` is the number of courses and `E` the number of prerequisites.

## ✅ Solution

```cpp
class Solution {
    // Map each course to its prerequisites
    unordered_map<int, vector<int>> preMap;
    // Store all courses along the current DFS path
    unordered_set<int> visiting;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int course) {
        if (visiting.count(course)) {
            // Cycle detected
            return false;
        }
        if (preMap[course].empty()) {
            return true;
        }

        visiting.insert(course);
        for (int pre : preMap[course]) {
            if (!dfs(pre)) {
                return false;
            }
        }
        // Course that can be taken
        visiting.erase(course); // no long visiting it
        preMap[course].clear(); // Set it to a empty list to return early True
        return true;
    }
};
```
