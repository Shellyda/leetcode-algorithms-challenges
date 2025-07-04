# Design Linked List

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/design-linked-list/)
- 🚦 Difficulty: 🟡 Medium

## Purpose

- Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
- A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
- If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

## ✅ Solution

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
