// Bipartite Graph(DFS Approach)
// Time Complexity: O(N+E)
// Bipartite Graph is a graph whose vertices can be divided into two disjoint sets U and V such that every edge connects a vertex in U to one in V.
#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int col, vector<int> adj[], vector<int> &color) {
    color[node] = col;
    for (auto neighbor : adj[node]) {
        if (color[neighbor] == -1) {
            if (!dfs(neighbor, 1 - col, adj, color)) {
                return false;
            }
        } else if (color[neighbor] == col) {
            return false;
        }
    }
    return true;
}

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
    vector<int> color(n , -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, adj, color)){
                cout << "Not Bipartite" << endl;
                return 0;
            }
        }
    }
    cout << "Bipartite" << endl;
    return 0;
}