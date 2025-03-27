// Cheapest Flights within K stops
// URL: https://leetcode.com/problems/cheapest-flights-within-k-stops/


#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    queue<pair<int, pair<int, int>>> q;
    for (auto it : flights)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v, w});
    }
    vector<int> dist(n, INT_MAX);
    q.push({0, {src, 0}});

    // queue me processign karwate hai
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int steps = it.first;
        int node = it.second.first;
        int wt = it.second.second;
        if (steps > k)
            continue;
        for (auto iter : adj[node])
        {
            if (wt + iter.second < dist[iter.first])
            {
                dist[iter.first] = wt + iter.second;
                q.push({steps + 1, {iter.first, dist[iter.first]}});
            }
        }
    }
    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}
int main()
{
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0, dst = 2, k = 1;
    cout << findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}