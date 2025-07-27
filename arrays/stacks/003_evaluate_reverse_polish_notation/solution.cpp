#include <stack>
#include <vector>
#include <string>

using namespace std;

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
};