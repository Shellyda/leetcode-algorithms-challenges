
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Math -> 2*slow = fast
// C -> clyce length
// X -> point where fast and slow meet
// (C - X) -> distance they run to meet
// so, the rest of the path is X, as C = C - X + X
// P -> distance pointers run to start cycle
//  2*(P + C - X) = P + C + (C - X)
// P = X -> start new slow2 pointer at begin to it meet the original slow pointer at the node which cycle starts

// Runs (C - X) distance to fast and slow pointers meet

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