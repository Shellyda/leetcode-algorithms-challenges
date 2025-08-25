# Maximum Twin Sum of a Linked List

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **Find the middle of the list (always even length)**

   - A **fast** pointer moves two steps at a time, while a **slow** pointer moves one step.
   - When `fast` reaches the end, `slow` will be at the midpoint.
   - This splits the list into two halves.

2. **Reverse the second half of the list**

   - Starting from the `slow` pointer (the middle), the algorithm reverses the second half in-place.
   - After reversal, the tail of the original list becomes the head of this reversed half.
   - This allows traversal from both the start and the end simultaneously.

3. **Calculate twin sums**

   - Initialize two pointers:

     - `firstPart` pointing to the head of the original list.
     - `secondPart` pointing to the head of the reversed second half.

   - Traverse both halves in parallel.
   - At each step, compute `firstPart->val + secondPart->val`.
   - Keep track of the **maximum sum** seen so far.

4. **Return the result**

   - After finishing the traversal, the stored maximum is the answer.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        int res = 0;
        // 1. find the second middle of list
        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 2. reverse the second part of list
        ListNode *curr = slow, *prev = nullptr;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. use reversed second part to sum twins
        ListNode *secondPart = prev, *firstPart = head;

        while (secondPart)
        {
            res = max(res, secondPart->val + firstPart->val);
            secondPart = secondPart->next;
            firstPart = firstPart->next;
        }

        return res;
    }
};
```
