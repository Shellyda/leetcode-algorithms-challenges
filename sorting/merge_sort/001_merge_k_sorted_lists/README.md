# Merge K Sorted Lists

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/merge-k-sorted-lists/)
- 🚦 Difficulty: 🔴 Hard

## 💡 Approach

- Merge Lists one by one

## 🕒 Time and Space Complexity

- Time: O(n\*k)
- Space: O(1)

> Where `k` is the total number of lists and `n` the total number of nodes across `k` lists

## ✅ Solution

```cpp
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        return mergeHelper(lists, 0, lists.size() - 1);
    }

private:
    ListNode *mergeHelper(vector<ListNode *> &lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        int mid = left + (right - left) / 2;
        ListNode *l1 = mergeHelper(lists, left, mid);
        ListNode *l2 = mergeHelper(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
```
