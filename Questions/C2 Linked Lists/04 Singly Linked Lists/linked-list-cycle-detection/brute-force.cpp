#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Not cool way of resolution but was the first way in mind to do it
// O(n^2) time complexity

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        vector<ListNode *> arr;

        while (head) // O(n)
        {
            arr.push_back(head);
            head = head->next;

            bool exists = find(begin(arr), end(arr), head) != end(arr); // O(n)

            if (exists)
                return true;
        }

        return false;
    }
};
