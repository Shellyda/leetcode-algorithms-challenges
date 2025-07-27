# Evaluate Reverse Polish Notation

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/evaluate-reverse-polish-notation)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- The code evaluates a Reverse Polish Notation (RPN) expression using a stack.
- It iterates over each token in the input:

  - If the token is a number, it pushes it onto the stack.
  - If the token is an operator (`+`, `-`, `*`, `/`), it pops the top two numbers from the stack, applies the operation, and pushes the result back.

- The helper function `getOperationResult` handles the actual arithmetic between the two popped operands.
- Finally, the result of the expression is the value on top of the stack.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    stack<int> stk;
    int evalRPN(vector<string> &tokens)
    {
        for (string token : tokens)
        {
            if ("+" == token || "-" == token || "*" == token || "/" == token)
            {
                int result = getOperationResult(token);
                stk.push(result);
            }
            else
            {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }

private:
    int getOperationResult(string operation)
    {
        int result;
        int operand2 = stk.top();
        stk.pop();
        int operand1 = stk.top();
        stk.pop();

        if ("+" == operation)
        {
            result = operand1 + operand2;
        }
        else if ("-" == operation)
        {
            result = operand1 - operand2;
        }
        else if ("*" == operation)
        {
            result = operand1 * operand2;
        }
        else
        {
            if (operand1 == 0 || operand2 == 0)
                return 0;
            result = operand1 / operand2;
        }

        return result;
    }
}
```
