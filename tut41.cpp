// Number of Islands II
// https://leetcode.com/problems/number-of-islands-ii/description/

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
    vector<vector<int>> positions = {{0, 0, 0, 0},
                                     {0, 1, 1, 0},
                                     {0, 0, 1, 0},
                                     {0, 0, 0, 0}};
    int n = positions.size(), m = positions[0].size();
    DisjointSet ds(n * m);
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    int vis[n][m];
    memset(vis, 0, sizeof(vis));
    vector<int> ans;
    int cnt = 0;
    for (auto it : positions)
    {
        int row = it[0], col = it[1];
        if (vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i], ncol = col + dc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                if (vis[nrow][ncol] == 1)
                {
                    int nodeNo = row * m + col;
                    int adjNodeNo = nrow * m + ncol;
                    if (ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo))
                    {
                        cnt--;
                        ds.unionByRank(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}