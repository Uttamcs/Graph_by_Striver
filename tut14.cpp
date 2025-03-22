// Find eventual safe nodes
// https://leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check)
{
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            if (dfs(it, graph, vis, pathVis, check))
            {
                return true;
            }
        }
        else if (pathVis[it])
        {
            return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    vector<int> check(n, 0);
    vector<int> safeNodes;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, pathVis, check);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (check[i] == 1)
        {
            safeNodes.push_back(i);
        }
    }

    for (auto it : safeNodes)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}