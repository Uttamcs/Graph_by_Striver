// Shortest Path in Undirected Graph with unit weights using BFS 
// Time Complexity: O(V + E)
// Space Complexity: O(V)


#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];
    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> dist(N, INT_MAX);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INT_MAX)
        {
            dist[i] = -1;
        }
    }
    return dist;
}
int main()
{
    int N = 9, M = 10;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    vector<int> ans =shortestPath(edges, N, M, 0);
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}