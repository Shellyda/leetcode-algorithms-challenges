# Two Dimensional Dynamic Programming

Let's consider a problem where the result of subproblems depend on two variables. This is where two-dimensional dynamic programming comes into play.

> Q: Count the number of unique paths from the top left to the bottom right. You are only allowed to move down or to the right.

Let's take the following grid into consideration where we are only allowed to move down or to the right. This implies that the only way we can go out of bounds is if our `r` pointer ends up at the number of rows and our `c` pointer at the number of `columns`.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/843cdb2b-3cbc-4146-f1fa-9d5e045da400/sharpen=1)

## The brute force approach

The brute force approach, starting from `0,0` would look like the following, where the blue arrows represent all of the paths we can take from a given coordinate. At each step we only have at most two choices: we either move down or to the right. To calculate unique paths from a given coordinate, we just sum the return values of both of the recursive calls.

The image below demonstrates part of the brute force approach but it is enough to see where it falls short. Knowing what you know about DP so far, are you able to figure out where unnecessary work is being done? Could we apply caching to this problem to make it more efficient?
The image below demonstrates part of the brute force approach but it is enough to see where it falls short. Knowing what you know about DP so far, are you able to figure out where unnecessary work is being done? Could we apply caching to this problem to make it more efficient?

![fib5](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/09a09764-c437-4153-891d-758a252b4d00/sharpen=1)

```cpp
// Brute Force - Time: O(2 ^ (n + m)), Space: O(n + m)
int bruteForce(int r, int c, int rows, int cols) {
    if (r == rows or c == cols) {
        return 0;
    }
    if (r == rows - 1 or c == cols - 1) {
        return 1;
    }
    return bruteForce(r + 1, c, rows, cols) +
        bruteForce(r, c + 1, rows, cols);
}
```

### The issue

The issue with this approach is that because we have to go down and right to calculate a value at every single coordinate. We will also end up visiting the same coordinate multiple times.

For small inputs this is not a problem, but as the input size grows, the number of recursive calls will grow exponentially.

The time complexity of the brute force approach is *O*(2^(_n_+_m_)), where `n` is the number of rows and `m` is the number of columns.

## The Dynamic Programming Approach

### Top-Down

Let us now see how we can make use of DP to save us some extra work we perform in the brute-force solution. The code will look like the following.

```cpp
// Memoization - Time and Space: O(n * m)
int memoization(int r, int c, int rows, int cols, vector<vector<int>>& cache) {
    if (r == rows or c == cols) {
        return 0;
    }
    if (cache[r][c] > 0) {
        return cache[r][c];
    }
    if (r == rows - 1 or c == cols - 1) {
        return 1;
    }
    cache[r][c] = memoization(r + 1, c, rows, cols, cache) +
        memoization(r, c + 1, rows, cols, cache);
    return cache[r][c];
}
```

Technically, this code is very similar to how it was in the brute force approach. In this case, we introduce a cache parameter, which stores the number of unique paths from a given coordinate. Let us now finish the rest of the visual that we demonstrated before, only this time using the DP approach.

![fib5](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/35b4bf20-b62f-4494-dbd2-233bc569df00/sharpen=1)

From the visual above, we find the paths for the `1`st row, `(1,0)` and that helps us find the paths for the `0`th rows. Notice that in the 4th step, when we want to calculate `(0,1)`, we don't have to calculate `(1,1)` again because it already resides in our cache. This saves us ton of unnecessary work.

### Bottom-Up

In this approach, we can start from the bottom right and work our way up to the top left. The time complexity will still be the same, except this is an iterative approach. The order in which we perform these calculations is super important. We have to calculate these values from right to left, and this is because we can only get a return value when we hit a base case.

In this case we actually don't even need a full grid to calculate values at any given row. Meaning, to calculate values of the `n`th row, we only need values of `n-1` row. Then, we can update our previous row to be our current row. Sound familiar? We followed the exact same approach in the fibonacci solution!

```cpp
// Dynamic Programming - Time: O(n * m), Space: O(m), where m is num of cols
int dp(int rows, int cols) {
    int *prevRow = new int[cols]();

    for (int r = rows - 1; r >= 0; r--) {
        int* curRow = new int[cols]();
        curRow[cols - 1] = 1;
        for (int c = cols - 2; c >= 0; c--) {
            curRow[c] = curRow[c + 1] + prevRow[c];
        }
        prevRow = curRow;
    }
    return prevRow[0];
}
```

Because we mentioned that we need only a previous row to calculate the values at any given row, we can initialize an initial row with all `0`s to calculate the bottom-most row. Our first for loop decrements the row number and at each row number, we initialize a row full of `0`s, and assign `1` to the right-most column, because that is our return value. We then use the inner for loop to go through every column in the row and calculate its value in the same way we demonstrated in the visuals before.

The time complexity of this approach is still *O*(*n*∗*m*), where `n` is the number of rows and `m` is the number of columns. The space complexity is *O*(_m_), where `m` is the number of columns, since we only have up to two rows in memory at any given time.
