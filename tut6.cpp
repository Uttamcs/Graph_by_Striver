// Rotting Oranges

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    int cntFresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            if (grid[i][j] == 1)
                cntFresh++;
        }
    }
    int tm = 0, cnt = 0;
    vector<int> delRow = {-1, 0, 0, 1};
    vector<int> delCol = {0, 1, -1, 0};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        tm = max(tm, time);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0)
            {
                q.push({{newRow, newCol}, time + 1});
                vis[newRow][newCol] = 2;
                cnt++;
            }
        }
    }
    if (cnt != cntFresh)
        return -1;
    return tm;
}
int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid);
    return 0;
}