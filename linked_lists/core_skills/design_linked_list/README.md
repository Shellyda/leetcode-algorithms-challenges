# Design Linked List

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/design-linked-list/)
- 🚦 Difficulty: 🟡 Medium

## Purpose

- Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
- A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
- If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

## ✅ Solution 01 - Using Singly Linked List

```cpp
class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val, ListNode* next) : val(val), next(next) {}
        ListNode(int val) : val(val), next(nullptr) {}
    };

public:
    MyLinkedList() {
        head = new ListNode(0, nullptr);
        size = 0;
    }

    int get(int index) {
        if (index >= size) return -1;
        return getPrev(index)->next->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        ListNode* prev = getPrev(index);
        ListNode* node = new ListNode(val, prev->next);
        prev->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size) return;
        ListNode* prev = getPrev(index);
        ListNode* toDelete = prev->next;
        prev->next = prev->next->next;
        delete toDelete;
        size--;
    }

private:
    ListNode* head;
    int size;

    ListNode* getPrev(int index) {
        ListNode* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur;
    }
};
```

## ✅ Solution 02 - Using Doubly Linked List

```cpp
class MyLinkedList
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode(int val = 0, ListNode *next = nullptr, ListNode *prev = nullptr)
        {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };

public:
    ListNode *head;
    ListNode *tail;
    int size;

    MyLinkedList()
    {
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ListNode *getPrev(int index)
    {
        if (index <= size / 2)
        {
            ListNode *cur = head;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            return cur;
        }
        else
        {
            ListNode *cur = tail;
            for (int i = 0; i < size - index + 1; i++)
            {
                cur = cur->prev;
            }
            return cur;
        }
    }

    int get(int index)
    {
        if (index >= size)
            return -1;
        return getPrev(index)->next->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        ListNode *node = new ListNode(val);
        ListNode *prev = getPrev(index);
        ListNode *next = prev->next;
        prev->next = node;
        node->prev = prev;
        node->next = next;
        next->prev = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        ListNode *prev = getPrev(index);
        ListNode *cur = prev->next;
        ListNode *next = cur->next;
        prev->next = next;
        next->prev = prev;
        delete cur;
        size--;
    }
};
```
