# Linked List Cycle Detection

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/linked-list-cycle/)
- 🚦 Difficulty: 🟢 Easy

> Second look at this question [here](https://github.com/Shellyda/30-days-algorithms-challenge/blob/main/linked_lists/fast_and_slow/003_linked_list_cycle_detection) using fast and slow pointers approach

## 💡 Approach

1. **Maintain a vector of visited nodes** (`arr`).

   - Each time the loop visits a node, it stores the current pointer (`head`) in the vector.

2. **Move forward in the list**:

   - Before moving, advance `head = head->next`.
   - After moving, check if this new `head` is already in the vector.

3. **Cycle detection**:

   - If the current `head` is found inside the vector, it means we’ve already visited this node before → so a **cycle exists**, return `true`.

4. **Termination**:

   - If the traversal ends because `head` becomes `nullptr`, it means the list has no cycle → return `false`.

## 🕒 Time and Space Complexity

- Time: O(n^2)
  - Because each `find` call scans the entire vector, and we may do this for every node.
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        vector<ListNode *> arr;

        while (head)
        {
            arr.push_back(head);
            head = head->next;

            bool exists = find(begin(arr), end(arr), head) != end(arr);

            if (exists)
                return true;
        }

        return false;
    }
};
```
