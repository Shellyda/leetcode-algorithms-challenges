#include <algorithm>
using std::max;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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