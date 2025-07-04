# Implement Stack using Queues

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/implement-stack-using-queues/description/)
- 🚦 Difficulty: 🟢 Easy

## Purpose

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

## ✅ Solution

```cpp
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
```
