// Topological Sort using DFS
// Time Complexity: O(N+E)
// Space Complexity: O(N+E)


#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& stack) {
    visited[node] = true;
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, adj, visited, stack);
        }
    }
    stack.push(node);
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}