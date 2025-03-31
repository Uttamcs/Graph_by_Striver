// Prim's Algorithm - A spanning tree is a tree in which we have N nodes(i.e. All the nodes present in the original graph) and N-1 edges and all nodes are reachable from each other.
// A minimum spanning tree is a spanning tree in which the sum of the weights of the edges is minimum. Prim's algorithm is used to find the minimum spanning tree of a graph. It works as follows:
//  - Finds the minimum spanning tree of a graph
//  - Uses a priority queue to find the minimum edge
//  - Greedily adds edges to the tree until all vertices are included
//  - Time complexity: O(E log V), where E is the number of edges and V is the number of vertices
//  - Space complexity: O(V + E), where V is the number of vertices and E is the number of edges

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2},{0, 3, 6},{1, 2, 3},{1, 3, 8},{1, 4, 5},{4, 2, 7}};
    vector<vector<int>> adj[V];
    for(auto it : edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0}); 
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if(vis[node]) continue; 
        vis[node] = 1; 
        sum += wt; 
        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];
            if(!vis[adjNode]){
                pq.push({edgeWeight, adjNode});
            }
        }
    }
    cout << sum << endl;

    return 0;
}