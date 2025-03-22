// Topological Sort using BFS (Kahn's Algorithm)
// Time Complexity: O(N+E)
// Space Complexity: O(N+E)

#include <bits/stdc++.h>
using namespace std;
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
    vector<int>inDegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }
    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int>res;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for (auto it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}