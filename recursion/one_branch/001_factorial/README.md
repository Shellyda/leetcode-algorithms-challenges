# factorial

## Purpose

- Study one-branch recursive implementation

## ✅ Solution

```cpp
// Recursive implementation of n! (n-factorial) calculation
int factorial(int n)
{
    // Base case: n = 0 or 1
    if (n <= 1)
    {
        return 1;
    }
    // Recursive case: n! = n * (n - 1)!
    return n * factorial(n - 1);
}
```
