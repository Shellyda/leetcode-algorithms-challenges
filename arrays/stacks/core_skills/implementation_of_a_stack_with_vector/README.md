# Implementation of a Stack with vector

## Purpose

- Use a vector to create a Stack behavior

## ✅ Solution

```cpp
class Stack
{
public:
    vector<int> stack_;

    Stack() {};

    void push(int n)
    {
        stack_.push_back(n);
    }

    int pop()
    {
        int res = stack_[stack_.size() - 1];
        stack_.pop_back();
        return res;
    }
};
```
