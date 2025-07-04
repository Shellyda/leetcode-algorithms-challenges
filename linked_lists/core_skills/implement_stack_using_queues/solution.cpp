struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MyStack
{
public:
    ListNode *topNode = nullptr;

    MyStack()
    {
    }

    void push(int x)
    {
        ListNode *newNode = new ListNode(x);
        if (empty())
        {
            topNode = newNode;
        }
        else
        {
            newNode->next = topNode;
            topNode = newNode;
        }
    }
    int pop()
    {
        int val = topNode->val;
        topNode = topNode->next;

        return val;
    }

    int top()
    {
        return topNode->val;
    }

    bool empty()
    {
        return !topNode;
    }
};