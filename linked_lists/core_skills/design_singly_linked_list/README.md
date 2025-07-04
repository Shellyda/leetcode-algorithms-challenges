# Design Singly Linked List

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/singlyLinkedList)
- 🚦 Difficulty: 🟢 Easy

## Purpose

Design a Singly Linked List class.

Your LinkedList class should support the following operations:

- `LinkedList()` will initialize an empty linked list.
- `int get(int i)` will return the value of the ith node (0-indexed). If the index is out of bounds, return -1.
- `void insertHead(int val)` will insert a node with val at the head of the list.
- `void insertTail(int val)` will insert a node with val at the tail of the list.
- `bool remove(int i)` will remove the ith node (0-indexed). If the index is out of bounds, return false, otherwise return true.
- `int[] getValues()` return an array of all the values in the linked list, ordered from head to tail.

## ✅ Solution

```cpp
class LinkedList
{
private:
    ListNode *head;
    ListNode *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index)
    {
        ListNode *curr = head;
        int i = 0;
        while (curr && i < index)
        {
            curr = curr->next;
            i++;
        }
        return curr ? curr->value : -1;
    }

    void insertHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(int index)
    {
        if (index < 0 || !head)
            return false;

        if (index == 0)
        {
            ListNode *temp = head;
            head = head->next;
            if (!head)
                tail = nullptr;
            delete temp;
            return true;
        }

        ListNode *curr = head;
        for (int i = 1; i < index; i++)
        {
            if (!curr->next)
                return false;
            curr = curr->next;
        }

        ListNode *toDelete = curr->next;
        if (!toDelete)
            return false;

        curr->next = toDelete->next;
        if (toDelete == tail)
            tail = curr;
        delete toDelete;
        return true;
    }

    vector<int> getValues()
    {
        vector<int> values;
        ListNode *curr = head;
        while (curr)
        {
            values.push_back(curr->value);
            curr = curr->next;
        }
        return values;
    }
};
```
