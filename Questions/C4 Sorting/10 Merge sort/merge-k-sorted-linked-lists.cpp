#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

ListNode *createList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    ListNode *l1 = createList({1, 2, 4});
    ListNode *l2 = createList({1, 3, 5});
    ListNode *l3 = createList({3, 6});

    vector<ListNode *> lists = {l1, l2, l3};

    Solution sol;
    ListNode *mergedHead = sol.mergeKLists(lists);

    cout << "Merged list:\n";
    printList(mergedHead);

    return 0;
}
