#include <stack>
using std::stack;

class MinStack
{
public:
    stack<int> stk;
    stack<int> minStk;
    MinStack() {}

    void push(int val)
    {
        stk.push(val);

        if (minStk.empty() || val <= minStk.top())
        {
            minStk.push(val);
        }
    }

    void pop()
    {
        if (stk.top() == minStk.top())
        {
            minStk.pop();
        }
        stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minStk.top();
    }
};
