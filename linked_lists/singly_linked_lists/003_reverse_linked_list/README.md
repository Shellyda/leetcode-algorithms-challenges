# Reverse linked list

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/reverse-linked-list/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Set `curr->next` node to be the `prev` one, always updating in each loop `prev` with `curr` node

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
```
