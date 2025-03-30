// Number of ways to Arrive at Destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

#include <bits/stdc++.h>
using namespace std;

int solve(int v, vector<vector<int>> &edges, int source, int destination, int maxTime)
{
    vector<vector<pair<int, int>>> adj(v);
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    vector<int> dist(v, INT_MAX), ways(v, 0);
    dist[source] = 0;
    ways[source] = 1;
    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto it : adj[u])
        {
            int node = it.first, wt = it.second;
            if (d + wt <= maxTime && dist[node] > d + wt)
            {
                dist[node] = d + wt;
                ways[node] = ways[u];
                pq.push({dist[node], node});
            }
            else if (dist[node] == d + wt)
            {
                ways[node] += ways[u];
            }
        }
        return ways[destination];
    }
}

int main()
{
    int v = 7;
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 4}, {2, 4, 5}, {3, 4, 6}, {4, 5, 7}};
    int source = 0, destination = 6, maxTime = 8;
    cout << solve(v, edges, source, destination, maxTime) << endl;
    return 0;
}
