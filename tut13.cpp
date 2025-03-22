// Detect cycle in a directed graph using DFS

#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int node, vector<int> adj[], vector<int> &vis, vector<int> &parent)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            parent[it] = node;
            if (isCyclic(it, adj, vis, parent))
                return true;
        }
        else if (parent[node] != it)
            return true;
    }
    return false;
};
int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    vector<int> parent(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (isCyclic(i, adj, vis, parent))
            {
                cout << "Cycle is present" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle is not present" << endl;
    return 0;
}