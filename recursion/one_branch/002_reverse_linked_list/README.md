# Reverse linked list

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/reverse-linked-list/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Set `curr->next` node to be the `prev` one, always updating in each loop `prev` with `curr` node
- But using recursion

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};
```
