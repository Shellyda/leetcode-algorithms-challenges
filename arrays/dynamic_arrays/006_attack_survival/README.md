# C - Attack Survival

- 🧩 Problem link: [AtCoder Beginner Contest 141](https://atcoder.jp/contests/abc141/submissions/69443014)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. **Read input values**

   - Read `N` (number of players), `K` (initial points), and `Q` (number of correct answers).

2. **Initialize scores**

   - Create a vector `scores` of size `N`, filled with 0.
   - This will track how many times each player answered correctly.

3. **Process correct answers**

   - Loop `Q` times.
   - For each input `A`, increment `scores[A - 1]`.
   - After this loop, `scores[i]` = number of correct answers by player `i+1`.

4. **Compute final points and survival**

   - For each player `i` from `0` to `N-1`:

     - Calculate `points = K - (Q - scores[i])`.

       - `Q - scores[i]` = how many times they lost a point.
       - `K - (Q - scores[i])` = final score.

     - If `points > 0`, print **"Yes"** (survives).
     - Else, print **"No"** (eliminated).

## 🕒 Time and Space Complexity

- Time: O(N + Q)
- Space: O(N)

> Where `N` is and `Q` is

## ✅ Solution

```cpp
int main()
{
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> scores(N, 0);

    for (int i = 0; i < Q; i++)
    {
        int A;
        cin >> A;
        scores[A - 1]++;
    }

    for (int i = 0; i < N; i++)
    {
        if ((K - (Q - scores[i])) > 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
```
