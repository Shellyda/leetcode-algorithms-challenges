# Validate Parentheses

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/valid-parentheses/description/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

```cpp
   stack stk

   for each char of string
        if c is ( or { or [:
            stk.push(c)
        else
            stk.isEmpty() return false

            chat top = stk.top()

            if c is ) and top != (:
                return false
            ... also for others cases

    return stk.isEmpty()
    // if is empty means all brackets
    // were closed in correct order
```

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stk.push(c);
            }
            else
            {
                if (stk.empty())
                {
                    return false;
                }

                char top = stk.top();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{'))
                {
                    return false;
                }

                stk.pop();
            }
        }

        return stk.empty();
    }
```
