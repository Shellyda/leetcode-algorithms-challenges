#include <vector>

using std::vector;

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
