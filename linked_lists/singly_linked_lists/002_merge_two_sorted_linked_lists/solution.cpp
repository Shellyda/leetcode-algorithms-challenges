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