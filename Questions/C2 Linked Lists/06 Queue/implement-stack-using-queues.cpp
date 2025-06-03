#include <iostream>
using std::cout;
using std::endl;

class ListNode
{
public:
    int val;
    ListNode *next = nullptr;

    ListNode(int val_)
    {
        val = val_;
    }
};

class MyStack
{
public:
    ListNode *topNode = nullptr;

    MyStack()
    {
    }

    void push(int x)
    {
        ListNode *newNode = new ListNode(x);
        if (empty())
        {
            topNode = newNode;
        }
        else
        {
            newNode->next = topNode;
            topNode = newNode;
        }
    }
    int pop()
    {
        int val = topNode->val;
        topNode = topNode->next;

        return val;
    }

    int top()
    {
        return topNode->val;
    }

    bool empty()
    {
        return !topNode;
    }
};

int main()
{
    MyStack s;

    s.push(1);
    s.push(2);
    s.top();
    s.pop();
    s.empty();

    return 0;
}