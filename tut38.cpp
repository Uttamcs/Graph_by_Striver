// Number of Provinces using Disjoint Set Union

#include <bits/stdc++.h>
using namespace std;

class Disjointset
{
public:
    vector<int> rank, parent;
    Disjointset(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findparent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]);
    }

    int unionByRank(int u, int v)
    {
        int op1 = findparent(u);
        int op2 = findparent(v);
        if (op1 == op2)
            return 0;
        if (rank[op1] < rank[op2])
            parent[op1] = op2;
        else if (rank[op2] < rank[op1])
            parent[op2] = op1;
        else
        {
            parent[op2] = op1;
            rank[op1]++;
        }
        return 1;
    }
};

int main()
{
    vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    int n = adj.size();
    Disjointset ds(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                ds.unionByRank(i, j);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.findparent(i) == i)
            count++;
    }
    cout << count << endl;
    return 0;
}
