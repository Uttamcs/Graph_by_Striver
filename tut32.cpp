// Bellman Ford Algorithm
// Time Complexity: O(V*E)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, pair<int, int>>> edges = {
        {0, {1, 5}},
        {1, {0, 3}},
        {1, {2, -1}},
        {2, {0, 1}}};

    int V = 3;
    vector<int> dist(V, INT_MAX);
    int src = 2;
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge.first;
            int v = edge.second.first;
            int w = edge.second.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second.first;
        int w = edge.second.second;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative weight cycle detected" << endl;
            return 0;
        }
    }

    cout << "Shortest distances from source " << src << " are:" << endl;
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF" << " ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
