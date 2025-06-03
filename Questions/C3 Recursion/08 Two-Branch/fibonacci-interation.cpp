#include <iostream>
using namespace std;

// Time complexity O(n)
int fibonacci(int n)
{
    if (n <= 0)
        return;

    int a = 0, b = 1;

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        long long nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
}