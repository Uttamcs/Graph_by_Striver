// Accounts merge

// https://leetcode.com/problems/accounts-merge/description/

#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main()
{
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};
    DisjointSet ds(accounts.size());
    unordered_map<string, int> emailToIndex;
    int n = accounts.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string mail = accounts[i][j];
            if (emailToIndex.find(mail) == emailToIndex.end())
            {
                emailToIndex[mail] = i;
            }
            else
            {
                ds.unionByRank(i, emailToIndex[mail]);
            }
        }
    }
    vector<string> mergedEmails[n];
    for (auto it : emailToIndex)
    {
        string mail = it.first;
        int index = ds.findUParent(it.second);
        mergedEmails[index].push_back(mail);
    }
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mergedEmails[i].size() > 0)
        {
            sort(mergedEmails[i].begin(), mergedEmails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedEmails[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
    }
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
