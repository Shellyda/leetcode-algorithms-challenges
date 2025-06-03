class MyLinkedList
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val, ListNode *next) : val(val), next(next) {}
        ListNode(int val) : val(val), next(nullptr) {}
    };

public:
    MyLinkedList()
    {
        head = new ListNode(0, nullptr);
        size = 0;
    }

    int get(int index)
    {
        if (index >= size)
            return -1;
        return getPrev(index)->next->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        ListNode *prev = getPrev(index);
        ListNode *node = new ListNode(val, prev->next);
        prev->next = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        ListNode *prev = getPrev(index);
        ListNode *toDelete = prev->next;
        prev->next = prev->next->next;
        delete toDelete;
        size--;
    }

private:
    ListNode *head;
    int size;

    ListNode *getPrev(int index)
    {
        ListNode *cur = head;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur;
    }
};