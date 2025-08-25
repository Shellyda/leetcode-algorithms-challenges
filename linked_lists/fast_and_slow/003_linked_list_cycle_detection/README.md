# Linked List Cycle Detection

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/linked-list-cycle/)
- 🚦 Difficulty: 🟢 Easy

> Already completed this question in another way before learning fast and slow approach properly. [check here](https://github.com/Shellyda/30-days-algorithms-challenge/blob/main/linked_lists/singly_linked_lists/001_linked_list_cycle_detection)

## 💡 Approach

1. **Initialize two pointers**:

   - `slow` moves one step at a time.
   - `fast` moves two steps at a time.

2. **Traverse the list**:

   - While `fast` and `fast->next` are not `nullptr`, keep moving the pointers.
   - If at any point `fast` and `slow` point to the same node, a **cycle exists**.

     - This happens because `fast` “laps” `slow` inside the cycle.

3. **Termination**:

   - If traversal ends because `fast` reaches `nullptr` (or `fast->next` is `nullptr`), it means the list has an end, so there’s **no cycle**.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

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
