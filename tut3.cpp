// Number of provinces

#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v + 1];
    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(v + 1, 0);
    int ans = 0;
    for (int i = 0; i < v; i++){
        if(!vis[i]){
            ans++;
            dfs(i, adj, vis);
        }
    }
    cout << ans << endl;
    return 0;
}