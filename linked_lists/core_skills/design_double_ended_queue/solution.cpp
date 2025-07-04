#include <iostream>
using std::cout;
using std::endl;

class ListNode
{
public:
    int val;
    ListNode *next = nullptr;
    ListNode *prev = nullptr;

    ListNode(int val_)
    {
        val = val_;
    }
};

class Deque
{
public:
    ListNode *left = nullptr;
    ListNode *right = nullptr;

    Deque()
    {
    }

    bool isEmpty()
    {
        return !left && !right;
    }

    void append(int value)
    {
        ListNode *newNode = new ListNode(value);
        if (isEmpty())
        {
            left = right = newNode;
        }
        else
        {
            newNode->prev = right;
            right->next = newNode;
            right = right->next;
        }
    }

    void appendleft(int value)
    {
        ListNode *newNode = new ListNode(value);
        if (isEmpty())
        {
            left = right = newNode;
        }
        else
        {
            newNode->next = left;
            left->prev = newNode;
            left = left->prev;
        }
    }

    int pop()
    {
        if (isEmpty())
            return -1;

        int val = right->val;

        ListNode *prevNode = right->prev;
        if (!prevNode)
        {
            right = left = nullptr;
        }
        else
        {
            prevNode->next = right->next;
            right = prevNode;
        }

        return val;
    }

    int popleft()
    {
        if (isEmpty())
            return -1;

        int val = left->val;

        ListNode *nextNode = left->next;
        if (!nextNode)
        {
            left = right = nullptr;
        }
        else
        {
            nextNode->prev = nullptr;
            left = nextNode;
        }

        return val;
    }
};

int main()
{
    Deque list;

    cout << list.isEmpty() << endl;
    list.append(10);
    cout << list.isEmpty() << endl;
    list.appendleft(20);
    list.popleft();
    list.pop();
    list.pop();
    list.append(30);
    list.pop();
    cout << list.isEmpty() << endl;

    return 0;
}