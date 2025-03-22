//   Find eventual safe nodes in a graph (Using BFS)
//   https://leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &adj, vector<int> &inDegree, vector<int> &safeNodes)
{
    vector<vector<int>> revAdj(adj.size());

    for (int i = 0; i < adj.size(); i++)
    {
        for (auto it : adj[i])
        {
            revAdj[it].push_back(i);
        }
    }
    int n = revAdj.size();
    for (int i = 0; i < n; i++)
    {
        for (auto it : revAdj[i])
        {
            inDegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for (auto it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    sort(safeNodes.begin(), safeNodes.end());
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
    vector<int> safeNodes;
    vector<int> inDegree(n, 0);
    solve(adj, inDegree, safeNodes);
    for (auto it : safeNodes)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}