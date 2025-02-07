// Number of Distinct Islands

#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0)
{
    vis[row][col] = 1;
    int m = grid.size();
    int n = grid[0].size();
    vec.push_back({row - row0, col - col0});
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
        {
            dfs(nRow, nCol, vis, grid, vec, row0, col0);
        }
    }
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 0}, {1, 1, 0}, {0, 0, 0}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, vis, grid, vec, i, j);
                st.insert(vec);
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}