// Maximum Connected Group

#include <bits/stdc++.h>
using namespace std;
class Disjoint
{
    public:
    vector<int> rank, parent, size;

    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
bool isValid(int row, int col, int n, int m)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}
int main()
{
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    // vector<vector<int>> grid = {{1, 1}, {1, 0}, {0, 1}};
    int n = grid.size(), m = grid[0].size();
    int vis[n][m];
    Disjoint ds(n * m);

    // Step 1: Create a disjoint set for each cell in the grid
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (grid[row][col] == 0)
                continue;
            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i], nc = col + dc[i];
                if (isValid(nr, nc, n, m) && grid[nr][nc] == 1)
                {
                    ds.unionBySize(row * m + col, nr * m + nc);
                }
            }
        }
    }
    // Step 2
    int maxi = 0;
    set<int> components;
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < m; col++)
        {
            if(grid[row][col] == 1) continue;
            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};
            for(int i = 0; i < 4; i++)
            {
                int nr = row + dr[i], nc = col + dc[i];
                if(isValid(nr, nc, n, m) && grid[nr][nc] == 1)
                {
                    components.insert(ds.findUParent(nr * m + nc));
                }
            }
            int totalSize = 0;
            for(auto it : components)
            {
                totalSize += ds.size[it];
            }
            totalSize += 1; 
            maxi = max(maxi, totalSize);
        }
    }
    for(int cell = 0; cell < n * m; cell++)
    {
        maxi = max(maxi, ds.size[ds.findUParent(cell)]);
    }
    cout << maxi << endl;
    return 0;
}