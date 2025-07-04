#include <vector>
using std::vector;

class ListNode
{
public:
    int value;
    ListNode *next;

    ListNode(int val) : value(val), next(nullptr) {}
};

class LinkedList
{
private:
    ListNode *head;
    ListNode *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index)
    {
        ListNode *curr = head;
        int i = 0;
        while (curr && i < index)
        {
            curr = curr->next;
            i++;
        }
        return curr ? curr->value : -1;
    }

    void insertHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(int index)
    {
        if (index < 0 || !head)
            return false;

        if (index == 0)
        {
            ListNode *temp = head;
            head = head->next;
            if (!head)
                tail = nullptr;
            delete temp;
            return true;
        }

        ListNode *curr = head;
        for (int i = 1; i < index; i++)
        {
            if (!curr->next)
                return false;
            curr = curr->next;
        }

        ListNode *toDelete = curr->next;
        if (!toDelete)
            return false;

        curr->next = toDelete->next;
        if (toDelete == tail)
            tail = curr;
        delete toDelete;
        return true;
    }

    vector<int> getValues()
    {
        vector<int> values;
        ListNode *curr = head;
        while (curr)
        {
            values.push_back(curr->value);
            curr = curr->next;
        }
        return values;
    }
};