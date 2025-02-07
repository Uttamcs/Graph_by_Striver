// No of Enclaves
#include <bits/stdc++.h>
using namespace std;
void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<int> delRow, vector<int> delCol)
{
    int m = grid.size();
    int n = grid[0].size();
    vis[r][c] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nRow = r + delRow[i];
        int nCol = c + delCol[i];

        if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
        {
            dfs(nRow, nCol, vis, grid, delRow, delCol);
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));

    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    for (int i = 0; i < n; i++)
    {
        // for uppar row
        if (grid[0][i] == 1 && !vis[0][i])
        {
            dfs(0, i, vis, grid, delRow, delCol);
        }
        // for niche wala row
        if (grid[m - 1][i] == 1 && !vis[m - 1][i])
        {
            dfs(m - 1, i, vis, grid, delRow, delCol);
        }
    }

    // col me chalte hai
    for (int i = 0; i < m; i++)
    {
        // for uppar row
        if (grid[i][0] == 1 && !vis[i][0])
        {
            dfs(i, 0, vis, grid, delRow, delCol);
        }
        // for niche wala row
        if (grid[i][n - 1] == 1 && !vis[i][n - 1])
        {
            dfs(i, n - 1, vis, grid, delRow, delCol);
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && grid[i][j])
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};

    cout << numEnclaves(grid);
    return 0;
}