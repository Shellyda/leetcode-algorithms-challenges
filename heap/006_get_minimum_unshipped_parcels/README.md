# Get Minimum unshipped parcels

- The "Amazon OA – Min Unshipped Parcels" type of question
- Find the minimum number of parcels that cannot be shipped if the parcels are shipped optimally

  > A set of `n` parcels needs to be shipped at an Amazon warehouse where the weight of the `i`th parcel is `weights[i]`. In a single trip, the truck can carry any one parcel with a weight strictly less than the truck's capacity, `max_wt`. After each trip, the capacity of the truck `max_wt` decreases by 1.

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) (Similar problem)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach 01 - Sorting

1. Sort parcels in **descending order** (`greater<int>()`).
2. Try to ship parcels one by one:

   - If the parcel’s weight `w` is **less than the current remaining capacity**, ship it (`sent++`)
   - Each shipped parcel **reduces the truck’s capacity by 1**
   - Stop if capacity hits 0

3. Return **unshipped parcels `weights.size() - sent`**.

```cpp
weights = {2, 3, 5}, max_wt = 4
```

1. Sort descending → `{5, 3, 2}`
2. capacity = 4

   - Try 5: `5 < 4`? No. skip
   - Try 3: `3 < 4`? Yes. ship → sent=1, capacity=3
   - Try 2: `2 < 3`? Yes. ship → sent=2, capacity=2

3. Done.

Shipped = 2, Total = 3 → **Unshipped = 1**

## 🕒 Time and Space Complexity

- Time: O(nlogn)
- Space: O(1)

## ✅ Solution

```cpp
int getMinUnshippedParcels(vector<int> weights, int max_wt)
{
    sort(weights.begin(), weights.end(), greater<int>()); // O(n log n)

    int capacity = max_wt, sent = 0;

    for (int w : weights)
    { // O(n)
        if (w < capacity)
        {
            sent++;
            capacity--;

            if (capacity == 0)
                break;
        }
    }

    return weights.size() - sent;
}
```
