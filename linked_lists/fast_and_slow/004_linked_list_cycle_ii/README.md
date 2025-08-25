# Linked List Cycle II

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/linked-list-cycle-ii/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **Cycle detection (first meeting point)**

   - Use two pointers:

     - `slow` moves one step.
     - `fast` moves two steps.

   - If the list has a cycle, `fast` and `slow` will eventually meet **inside the cycle**.
   - If `fast` reaches `nullptr`, there’s no cycle → return `nullptr`.

2. **Mathematical Proof of Floyd's Tortoise and Hare:**
   1. Let the distance between the head node and the node at which the cycle starts be denoted by `P`.
   2. Let the length of the cycle be denoted by `C`.
   3. Let the distance from the node at which slow and fast intersect to the node at which the cycle begins, be denoted by `X`.

> Using this information, we can derive that the distance between the start of the cycle and the node at which fast and slow intersect is `C−X`.

We know that `2∗slow=fast`. Using the information above, let's rewrite this equation in terms of the `C,X,P`, we get the following:

- **Step 1:** Rewrite in terms of `C,X,P` -> `2(P+C−X)=P+C+C−X`

- **Step 2:** Expand the brackets -> `2P+2C−2X=P+2C−X`

- **Step 3:** Now, we can bring like terms to the left side, which results in the following `P−X=0`

- **Step 4:** Isolate `P` -> `P=X`

  > So if `P=X`, it must be the case that `slow` and `slow2` are equally as far from the node where the cycle starts, due to the definition of Point 1 and 2 above.

- This means: if you start one pointer at `head` and keep the other at the meeting point, both moving one step at a time, they will meet at the **start of the cycle**.

3. **Finding the cycle start**

   - Initialize `slow2` at `head`.
   - Move `slow` (from meeting point) and `slow2` (from head) one step at a time.
   - They meet exactly at the **node where the cycle begins**.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/7ac41b86-462f-4e47-5eaf-03a845802200/sharpen=1)

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }

        if (!fast || !fast->next)
            return nullptr; // no cycle

        ListNode *slow2 = head; // start new slow2 pointer at begin to it meet the original slow pointer at the node which cycle starts

        while (slow2 != slow)
        {
            slow = slow->next;   // runs X
            slow2 = slow2->next; // runs P
        }

        return slow;
    }
};
```
