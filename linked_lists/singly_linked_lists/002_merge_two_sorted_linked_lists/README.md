# Merge two sorted linked lists

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/merge-two-sorted-lists)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Created a dummy node to avoid any edge case from empty list
- If one of lists is still with elements after loop, copy the rest of it

## 🕒 Time and Space Complexity

- Time: O(m + n)
- Space: O(m + n)

> `m` is the number of elements in `list1` and `n` is the number of elements in `list2`

## ✅ Solution

```cpp
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *node = &dummy; // init with dummy to avoid any edge case from empty list

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                node->next = list1;
                list1 = list1->next;
            }
            else
            {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        // if one of the lists is still with elements after the loop
        // copy the rest of it
        if (list1)
        {
            node->next = list1;
        }
        else
        {
            node->next = list2;
        }

        return dummy.next;
    }
};
```
