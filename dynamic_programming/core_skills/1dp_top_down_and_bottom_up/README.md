# One Dimensional Dynamic Programming

Simply put, it is an optimized version of recursion.

It takes a big problem and solves it by breaking it down into smaller problems. The reason we say it is optimized recursion is because it is often more optimal when it comes to time and space.

## Brute force

Let's go back to the fibonacci sequence which we solve earlier using recursion. We calculated the nth fibonacci number by using the formula: `F(n) = F(n-1) + F(n-2)` with the following code:

```cpp
// Brute Force - O(2^n)
int bruteForce(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return bruteForce(n - 1) + bruteForce(n - 2);
}
```

If we look at the tree for `bruteForce(5)` below, we can see we calculate `F(2)` three times, which is extra work since we have already calculated the value of `F(2)`. This does not seem like a big deal when the input is small but as the input grows, the amount of work done grows exponentially, which will become extremely slow if we have something like calculating fibonacci of 100.

![alt text](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/2589ccc7-7f6a-4ca7-43f6-290a11b48300/sharpen=1)

> DP tells us that we can avoid repeating this computation by a concept called memoization, which is a fancy word for caching.

## Top Down Approach (Memoization) - caching results

The idea here is that once we perform a computation, we can store it in a cache so that we do not have to repeat it. For example, if we calculate `F(3)`, we can store the result in a hash map or array, and then we can retrieve the result from the cache if we encounter the same computation again.

```cpp
// Memoization - Top-down Dynamic Programming - O(n)
int memoization(int n, unordered_map<int, int> *cache)
{
    if (n <= 1)
    {
        return n;
    }
    if (cache->count(n))
    {
        return (*cache)[n];
    }
    return memoization(n - 1, cache) + memoization(n - 2, cache);
}
```

Notice in the solution above that we have made a few key changes to the previous recursive solution:

    1. We added a `cache` parameter to the function, which in this case is a hash map.
    2. We added a base case to check if the value of `n` is in the cache. If it is, we return the value stored in the cache rather than making a recursive call.
    3. After we compute the value of `F(n)`, we store it in the cache so that we can retrieve it later if we need it.

## Bottom Up Approach (Tabulation)

We calculate the value of `n` by making use of `n−1` and `n−2`. Let us now suppose that we have an array of size `5` which will help us calculate the 5th fibonacci number, where the value stored at the `ith` index of the array represents the fibonacci value of `i`. This would look like the following:
`[0,1,1,2,3,5]`

The time complexity for this is O(n) and the space complexity is O(n) as well. The real question here is if we even need to allocate space for an entire array. If we think about it, we are only ever using the previous two values to calculate the current value.

So, if we take an array of size `2`, we can bring our space complexity down to O(1). By doing this, we can just store the fibonacci number at the 1st index in a temporary variable, calculate the next fibonacci number and overwrite the value the 1st index with the newly calculated fibonacci number, and finally overwrite the `0`th index with our temporary variable.

```cpp
// Tabulation - Bottom-up Dynamic Programming - O(n)
int dp(int n)
{
    if (n < 2)
    {
        return n;
    }

    int dp[] = {0, 1};
    int i = 2;
    while (i <= n)
    {
        int tmp = dp[1];
        dp[1] = dp[0] + dp[1];
        dp[0] = tmp;
        i++;
    }
    return dp[1];
}
```

![alt](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/0b6ae8e9-7ed0-4cf6-6f10-7548e9f16f00/sharpen=1)
With the code above, we also have a time complexity of O(n) because we are iterating all the way until `n`, and the number of our operations will be linear to the size of our `n`.

We also brought the space complexity to O(1) because regardless of how big our `n` gets, we will always just need an array of size 2.

> This is an example of 1-D dynamic programming because the result of every subproblem can be stored in a 1-D data structure that is proportional to `n`, where `n` is `nth` fibonacci number we are trying to calculate.
