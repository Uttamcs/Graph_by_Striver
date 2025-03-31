// Number of Operations to make Network Connected

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
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
    DisjointSet ds(n);
    int cntExtra = 0;
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        if (ds.findUParent(u) == ds.findUParent(v))
            cntExtra++;
        else
            ds.unionBySize(u, v);
    }
    int cntC = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.findUParent(i) == i)
            cntC++;
    }
    int ans = cntC - 1;
    if (cntExtra >= ans)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}