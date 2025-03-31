// Kruskal's algorithm
// - A minimum spanning tree is a spanning tree in which the sum of the weights of the edges is minimum. Kruskal's algorithm is used to find the minimum spanning tree of a graph. It works as follows: - Sort all the edges in non-decreasing order of their weight. - Pick the smallest edge.
// - Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it. - Repeat until there are (V-1) edges in the spanning tree. - Time complexity: O(E log E), where E is the number of edges. - Space complexity: O(V + E), where V is the number of vertices and E is the number of edges.

// Why Kruskal's algorithm is better than Prim's algorithm?
// - Kruskal's algorithm is better than Prim's algorithm because it is more efficient in terms of time complexity. Kruskal's algorithm has a time complexity of O(E log E), while Prim's algorithm has a time complexity of O(E log V). This means that Kruskal's algorithm is faster for dense graphs, while Prim's algorithm is faster for sparse graphs. Additionally, Kruskal's algorithm is easier to implement and understand than Prim's algorithm.
// - Kruskal's algorithm is more efficient for dense graphs, while Prim's algorithm is more efficient for sparse graphs. - Kruskal's algorithm is easier to implement and understand than Prim's algorithm. 


#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
int spanningTree(int V, vector<vector<int>> &edges) {
    DisjointSet ds(V);
    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });
    int mstCost = 0;
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (ds.findUParent(u) != ds.findUParent(v)) {
            mstCost += wt;
            ds.unionBySize(u, v);
        }
    }
    return mstCost;
}
int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    cout<<spanningTree(V, edges)<<endl;
    return 0;
}


