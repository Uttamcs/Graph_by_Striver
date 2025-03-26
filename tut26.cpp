// Shortest Path in Weighted undirected graph using Dijkstra's Algorithm
// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5; 

    vector<pair<int, int>> adj[n];
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 5});
    adj[2].push_back({1, 5});
    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});
    adj[0].push_back({3, 1});
    adj[3].push_back({0, 1});
    adj[3].push_back({4, 3});
    adj[4].push_back({3, 3});
    adj[2].push_back({4, 1});
    adj[4].push_back({2, 1});

    int src = 0;  
    int dest = 4; 
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first; 
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] != INT_MAX)
    {
        cout << "Shortest distance from " << src << " to " << dest << " is: " << dist[dest] << endl;
    }
    else
    {
        cout << "Destination " << dest << " is not reachable from source " << src << endl;
    }

    return 0;
}