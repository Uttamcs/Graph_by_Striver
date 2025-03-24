// Shortest path in Directed Acyclic Graph
// Time Complexity: O(V+E)
// Space Complexity: O(V)


#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &vis, stack<int> &st)
{
    vis[node] = true;
    for (auto &neighbor : adj[node])
    {
        if (!vis[neighbor.first])
        {
            dfs(neighbor.first, adj, vis, st);
        }
    }
    st.push(node);
}

int main()
{
    int V = 4, E = 2;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}};
    int src = 0;
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u].push_back({v, w});
    }
    vector<int> dist(V, INT_MAX);
    vector<bool> vis(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dist[node] != INT_MAX)
        {
            for (auto &neighbor : adj[node])
            {
                if (dist[neighbor.first] > dist[node] + neighbor.second)
                {
                    dist[neighbor.first] = dist[node] + neighbor.second;
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            dist[i] = -1;
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}