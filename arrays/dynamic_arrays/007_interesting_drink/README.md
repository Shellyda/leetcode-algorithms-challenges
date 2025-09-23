# A - Interesting Drink

- 🧩 Problem link: [Vjudge](https://vjudge.net/contest/750263#problem/A)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. **Read all drink prices** into an array.
2. **Sort** the prices in non-decreasing order.
3. For each query:

   - Read the maximum amount of money available.
   - Use **`upper_bound`** from the STL, which returns the first element _greater_ than the queried value.
   - The difference between that position and the beginning of the array tells us exactly how many prices are **≤ query value**.

4. Print that number as the result for the query.

In short: sort once, then answer each query efficiently with binary search.

```cpp
read N
read array prices of size N
sort(prices)

read Q
for each query:
    read x
    result = upper_bound(prices, x) - prices.begin()
    print result
```

## 🕒 Time and Space Complexity

- Time:

  - Sorting: O(N log N)
  - Each query with `upper_bound`: O(log N)
  - Total: O(N log N + Q log N)

- Space: O(N)

## ✅ Solution

```cpp
int main()
{
    int N, Q;
    cin >> N;

    vector<int> prices(N);

    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int input;
        cin >> input;

        int result = upper_bound(prices.begin(), prices.end(), input) - prices.begin();

        cout << result << endl;
    }

    return 0;
}
```
