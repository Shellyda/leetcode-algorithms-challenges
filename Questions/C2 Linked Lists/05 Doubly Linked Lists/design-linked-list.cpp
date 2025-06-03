class MyLinkedList
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode(int val = 0, ListNode *next = nullptr, ListNode *prev = nullptr)
        {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };

public:
    ListNode *head;
    ListNode *tail;
    int size;

    MyLinkedList()
    {
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ListNode *getPrev(int index)
    {
        if (index <= size / 2)
        {
            ListNode *cur = head;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            return cur;
        }
        else
        {
            ListNode *cur = tail;
            for (int i = 0; i < size - index + 1; i++)
            {
                cur = cur->prev;
            }
            return cur;
        }
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
        ListNode *node = new ListNode(val);
        ListNode *prev = getPrev(index);
        ListNode *next = prev->next;
        prev->next = node;
        node->prev = prev;
        node->next = next;
        next->prev = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        ListNode *prev = getPrev(index);
        ListNode *cur = prev->next;
        ListNode *next = cur->next;
        prev->next = next;
        next->prev = prev;
        delete cur;
        size--;
    }
};