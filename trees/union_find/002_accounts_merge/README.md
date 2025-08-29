# Accounts Merge

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/accounts-merge/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

Treat each **account index** as a node in a graph. If two accounts share an email, connect their nodes. Then, each connected component corresponds to one person. We use **Union–Find (Disjoint Set Union, DSU)** to efficiently build these components.

- `UnionFind(n)` with:

  - `parent[i]`: the representative (root) of the set containing `i`.
  - `rank[i]`: an upper bound on the tree height (used for balancing).
  - Optimizations:

    - **Path compression** in `find`: flattens trees for near O(1) finds.
    - **Union by rank** in `unionSets`: attaches the shallower tree under the deeper one.

- `unordered_map<string,int> emailToAcc`:

  - Maps each email to the **first** account index where it appeared.

- `map<int, vector<string>> emailGroup`:

  - Groups emails by the DSU **leader** (root account index). Using `map` just orders groups by leader index; `unordered_map` would also work.

### Algorithm steps

1. **Initialize DSU**

   ```cpp
   UnionFind uf(n);
   ```

   Each account is its own parent initially; ranks are zero.

2. **Scan emails and union accounts**

   ```cpp
   for each account i:
     for each email in accounts[i] (skip index 0, which is the name):
       if email has been seen:
         unionSets(i, emailToAcc[email]);
       else:
         emailToAcc[email] = i;
   ```

   - First time an email shows up, remember which account it belongs to.
   - Next times, we **union** the current account with the account that first had this email.
   - This ensures transitivity: if A shares with B, and B shares with C, then all A, B, C end up in the same set.

3. **Group emails by DSU leader**

   ```cpp
   for each (email, accId) in emailToAcc:
     leader = uf.find(accId);
     emailGroup[leader].push_back(email);
   ```

   - After DSU is built, each email is assigned to the **root account** of its component.

4. **Build the result**

   ```cpp
   for each (leader, emails) in emailGroup:
     sort(emails); // lexicographic order required by the problem
     merged = [ accounts[leader][0], ...emails ];
     res.push_back(merged);
   ```

   - The name is taken from the leader account (`accounts[leader][0]`).
   - Assumption consistent with the standard problem: all accounts in a merged component share the same name.

#### Notes

- **Union on shared emails** guarantees two accounts are in the same DSU set iff their email sets intersect (directly or transitively).
- **Grouping by leader** collects exactly the emails belonging to that component, with no duplicates (because you iterate emails from `emailToAcc`, where each email appears once).
- **Sorting** meets the output format requirement.

## 🕒 Time and Space Complexity

- DSU operations: Each `find/union` is **amortized** \~O(α(n)), where α is the inverse Ackermann function (practically constant).

- Email scan + unions: **O(m α(n))** ≈ **O(m)**.

- Grouping: **O(m α(n))** (due to `find`).

- Sorting per group: Suppose a group has `k` emails; sorting costs `O(k log k)`. Summed over all groups, worst case is **O(m log m)**.

* Time: O(m log m) -> (sorting dominates)
* Space: O(n + m) extra space

> Where `n` = number of accounts and `m` = total number of email entries across all accounts

## ✅ Solution

```cpp
class UnionFind
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    UnionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x1, int x2)
    {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2)
            return false;

        if (rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else if (rank[p1] < rank[p2])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p1] = p2;
            rank[p2]++;
        }
        return true;
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> emailToAcc; // email -> index of acc

        // Build union-find structure
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                const string &email = accounts[i][j];
                if (emailToAcc.count(email))
                {
                    uf.unionSets(i, emailToAcc[email]);
                }
                else
                {
                    emailToAcc[email] = i;
                }
            }
        }

        // Group emails by leader account
        map<int, vector<string>> emailGroup; // index of acc -> list of emails
        for (const auto &[email, accId] : emailToAcc)
        {
            int leader = uf.find(accId);
            emailGroup[leader].push_back(email);
        }

        // Build result
        vector<vector<string>> res;
        for (auto &[accId, emails] : emailGroup)
        {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[accId][0]);                      // acc name
            merged.insert(merged.end(), emails.begin(), emails.end()); // add the rest
            res.push_back(merged);
        }

        return res;
    }
};
```
