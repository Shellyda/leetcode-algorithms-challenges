# CD

- 🧩 Problem link: [UVA 624](https://onlinejudge.org/external/6/624.pdf)
- 🚦 Difficulty: A

## 💡 Approach

We need to choose a subset of tracks that best fits the tape capacity without exceeding it — maximizing the total length.
This is equivalent to the 0/1 Knapsack problem, where each track is an item, its length is the weight, and its value is also its weight (since we only care about total time).
We use top-down dynamic programming with memoization `(map<pair<int, int>, int>)` to store results for each state `(index, remaining_capacity)`.
To reconstruct the chosen tracks, another map stores the subset of tracks that led to the optimal sum.

## 🕒 Time and Space Complexity

- Time: O(n \* m)
- Space: O(n \* m) (memoized states stored in map, typically less than full table size)

> where `n` is the number of tracks and `m` is the tape capacity.

## ✅ Solution

```cpp
map<pair<int, int>, int> memo; // dp top-down
map<pair<int, int>, vector<int>> chosenTracks;

int dfs(int i, vector<int> &tracks, int capacity)
{
    if (i == (int)tracks.size() || capacity == 0)
        return 0;

    auto key = make_pair(i, capacity);
    if (memo.count(key))
        return memo[key];

    int skip = dfs(i + 1, tracks, capacity);
    vector<int> skipSet = chosenTracks[{i + 1, capacity}];

    int include = 0;
    vector<int> includeSet;

    int newCap = capacity - tracks[i];
    if (newCap >= 0)
    {
        include = tracks[i] + dfs(i + 1, tracks, newCap);
        includeSet = chosenTracks[{i + 1, newCap}];
        includeSet.insert(includeSet.begin(), tracks[i]);
    }

    if (include > skip)
    {
        memo[key] = include;
        chosenTracks[key] = includeSet;
    }
    else
    {
        memo[key] = skip;
        chosenTracks[key] = skipSet;
    }

    return memo[key];
}

int main()
{
    int n, numTracks;
    while (cin >> n >> numTracks)
    {
        vector<int> tracks(numTracks);
        for (int i = 0; i < numTracks; i++)
            cin >> tracks[i];

        memo.clear();
        chosenTracks.clear();

        int bestSum = dfs(0, tracks, n);
        vector<int> result = chosenTracks[{0, n}];

        for (int t : result)
            cout << t << " ";
        cout << "sum:" << bestSum << "\n";
    }

    return 0;
}
```
