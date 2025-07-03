# Linked List Cycle Detection

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/linked-list-cycle/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Using fast and slow pointers to check if the linked list
- If they meet in sometime so there is a cycle

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }

        return false;
    }
```
