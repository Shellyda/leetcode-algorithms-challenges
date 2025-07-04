# Design Double eneded Queue

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/queue)
- 🚦 Difficulty: 🟢 Easy

## Purpose

Design a Double-ended Queue class.

Your Deque class should support the following operations:

Deque() will initialize an empty queue.

- `bool isEmpty()` will return whether the queue is empty or not.
- `void append(int value)` will insert value at the end of the queue.
- `void appendleft(int val)` will insert value at the beginning of the queue.
- `int pop()` will remove and return the value at the end of the queue. If the queue is empty, return `-1`.
- `int popleft()` will remove and return the value at the beginning of the queue. If the queue is empty, return `-1`.

### Note: You should implement each operation in O(1) time complexity.

### Example 1:

#### Input:

```
["isEmpty", "append", 10, "isEmpty", "appendLeft", 20, "popLeft", "pop", "pop", "append", 30, "pop", "isEmpty"]
```

#### Output:

```
[true, null, false, null, 20, 10, -1, null, 30, true]
```

## ✅ Solution

```cpp
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
```
