class DynamicArray
{
public:
    int capacity;
    int *arr;
    int size = 0;

    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity];
    }

    int get(int i)
    {
        return arr[i];
    }

    void set(int i, int n)
    {
        arr[i] = n;
    }

    void pushback(int n)
    {
        if (size == capacity)
        {
            resize();
        }

        arr[size++] = n;
    }

    int popback()
    {
        return arr[--size];
    }

    void resize()
    {
        capacity = capacity * 2;
        int *newArr = new int[capacity];

        for (int i; i < size; i++)
        {
            newArr[i] = arr[i];
        }

        arr = newArr;
    }

    int getSize()
    {
        return size;
    }

    int getCapacity()
    {
        return capacity;
    }
};