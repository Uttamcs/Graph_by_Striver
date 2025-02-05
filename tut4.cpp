// Number of Islands

#include <bits/stdc++.h>
using namespace std;
void bfs(int r, int c, vector<vector<int>> &vis,
         vector<vector<char>> &grid)
{
    vis[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    int n = grid.size();
    int m = grid[0].size();
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0)
            {
                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (grid[row][col] == '1' && !vis[row][col])
            {
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << numIslands(grid);
    return 0;
}