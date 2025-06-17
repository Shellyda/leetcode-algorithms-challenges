#include <vector>
using std::vector;

class MinHeap
{
private:
    vector<int> heap;

    void percolateDown(int i)
    {
        // parent -> i / 2
        // leftchild -> 2 * i
        // rightchild -> 2 * i + 1

        while (2 * i < heap.size())
        { // respect the heap property that cant have a tree going from right to left

            if (2 * i + 1 < heap.size() && heap[2 * i + 1] < heap[2 * i] && heap[i] > heap[2 * i + 1])
            {
                int temp = heap[2 * i + 1];
                heap[2 * i + 1] = heap[i];
                heap[i] = temp;
                i = 2 * i + 1;
            }
            else if (heap[i] > heap[2 * i])
            {
                int temp = heap[2 * i];
                heap[2 * i] = heap[i];
                heap[i] = temp;
                i = 2 * i;
            }
            else
            {
                break;
            }
        }
    }

public:
    MinHeap()
    {
        heap.push_back(0); // dummy node
    }

    void push(int val)
    {
        heap.push_back(val);

        // parent -> i / 2
        // leftchild -> 2 * i
        // rightchild -> 2 * i + 1

        int i = heap.size() - 1;
        while (i > 1 && heap[i / 2] > heap[i])
        {
            int temp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = temp;
            i = i / 2;
        }
    }

    int pop()
    { // pop root
        if (heap.size() == 1)
            return -1;
        if (heap.size() == 2)
        {
            int root = heap[heap.size() - 1];
            heap.pop_back();
            return root;
        }

        int root = heap[1];

        // move the last value to root
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();

        // start from the root
        percolateDown(1);

        return root;
    }

    int top()
    {
        if (heap.size() == 1)
            return -1;
        return heap[1];
    }

    void heapify(const vector<int> &arr)
    {
        heap.clear();
        heap.push_back(0);

        heap.insert(heap.end(), arr.begin(), arr.end());

        int curr = (heap.size() - 1) / 2; // start from the parent from the element we just added

        while (curr > 0)
        {
            int i = curr;
            percolateDown(i);
            curr--;
        }
    }
};
