// Disjoint Set Union Find

#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    private:
        vector<int> rank, parent, size;
        public:
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        int findUParent(int node)
        {
            if(node==parent[node])
                return node;
            return parent[node]=findUParent(parent[node]);
        }
        void unionByRank(int u, int v)
        {
            int ulp_u=findUParent(u);
            int ulp_v=findUParent(v);
            if(ulp_u==ulp_v) return;
            if(rank[ulp_u]<rank[ulp_v])
            {
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u])
            {
                parent[ulp_v]=ulp_u;
            }
            else
            {
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u, int v)
        {
            int ulp_u=findUParent(u);
            int ulp_v=findUParent(v);
            if(ulp_u==ulp_v) return;
            if(size[ulp_u]<size[ulp_v])
            {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else
            {
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};
int main()
{
    int n=7;
    vector<vector<int>> edges={{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{4,2,7}};
    DisjointSet ds(n);
    ds.unionBySize(0,1);
    ds.unionBySize(0,3);
    ds.unionBySize(1,2);
    cout<<ds.findUParent(0)<<" "<<ds.findUParent(1)<<" "<<ds.findUParent(2)<<" "<<ds.findUParent(3)<<" "<<ds.findUParent(4)<<" "<<ds.findUParent(5)<<" "<<ds.findUParent(6)<<endl;
    return 0;
}