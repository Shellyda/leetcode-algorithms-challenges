#include <unordered_map>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class UnionFind
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    UnionFind(int n)
    {
        ;
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