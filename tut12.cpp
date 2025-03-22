// Bipartite Graph(BFS Approach)
// Time Complexity: O(N+E)
// Bipartite Graph is a graph whose vertices can be divided into two disjoint sets U and V such that every edge connects a vertex in U to one in V.
#include <bits/stdc++.h>
using namespace std;
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
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if(color[i] == -1){
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it: adj[node]){
                    if(color[it] == -1){
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                    else if(color[it] == color[node]){
                        cout << "Not Bipartite" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Bipartite" << endl;
    return 0;
}