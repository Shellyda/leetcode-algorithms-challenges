# D - Take ABC

- 🧩 Problem link: [AtCoder](https://atcoder.jp/contests/abc328/tasks/abc328_d?lang=en)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

**stack-like approach**:

- Traverse the input string character by character.
- Append each character to a `result` string (acting like a stack).
- Whenever the last 3 characters of `result` form `"ABC"`, remove them.
- At the end, the `result` string will be the final string after all removals.

This works because removals only affect the most recent characters, and by maintaining the stack, we handle cascading removals efficiently.

```cpp
read input string
result = ""

for each character c in input:
    append c to result
    if last 3 chars of result == "ABC":
        remove last 3 chars

print result
```

## 🕒 Time and Space Complexity

- Time Complexity:

  - Each character is processed once, and removals are constant-time on the back of the result.
  - Overall: O(N), where N is the length of the input string.

- Space Complexity:

  - We store the `result` string which in the worst case is size N.
  - Overall: O(N)

## ✅ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inputStr, result;
    cin >> inputStr;

    for (char c : inputStr)
    {
        result.push_back(c);

        int n = result.size();
        if (n >= 3 && result[n - 3] == 'A' && result[n - 2] == 'B' && result[n - 1] == 'C')
        {
            result.pop_back();
            result.pop_back();
            result.pop_back();
        }
    }

    cout << result << "\n";
    return 0;
}
```
