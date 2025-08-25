# Middle of the Linked List

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/middle-of-the-linked-list/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

The brute-force approach would be to iterate through the entire linked list, and using a variable, say `length`, keep track of the `length`. We can then run a for loop until `length / 2` and when we exit our for loop, we would have reached the middle.

This solution works and is also efficient, but there is a more elegant approach.

1. We have two pointers start at the head of the linked list, one `fast` and one `slow`.
2. Our `fast` pointer moves twice as `fast` as the `slow` pointer.
3. By the time the `fast` pointer gets to the end, the `slow` pointer would be at the middle of the linked list.

> This makes sense because if the `slow` pointer is traveling at half the speed of the `fast` pointer, and the `fast` pointer has reached the end, then the `slow` pointer must be in the middle.

**For odd length linked lists, we can start both pointers at the same location.**
![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/8bd0d1eb-afad-4560-c760-46bf8568ac00/sharpen=1)

**For even length linked lists, the middle can be one of two nodes**, just like there are two numbers when you want to find the median of a list of numbers.

- We can pick either one of of the nodes to be the middle. In the visual below, picking `3` means `fast` and `slow` both start at `head`.
- However, picking `2` means `fast` starts at `slow.next`, which makes sense because if `fast` starts ahead of `slow`, it exhausts itself faster.
  ![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/943710e2-1510-4071-fb5c-9758fa222100/sharpen=1)

> **What happens if the while loop only checks for existence of `fast` and not `fast.next`?** We will get an error. This is because by the time the `fast` pointer reaches the last node in the linked list, `fast.next == null`, which means that when we try and execute `fast = fast.next.next` in the while block, we are executing `null.next`, which does not actually exist!

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};
```
