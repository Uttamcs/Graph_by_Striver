// Shortest Path in Binary Matrix using Dijkstra's Algorithm
// https://www.leetcode.com/problems/shortest-path-in-binary-matrix/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    int n = grid.size();
    int m = grid[0].size();
    int dist[n][m];
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[0][0] = 1;
    pq.push({1, {0, 0}});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if (d > dist[r][c])
            continue;
        for (int i = 0; i < 8; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dist[nr][nc] > d + 1)
            {
                dist[nr][nc] = d + 1;
                pq.push({dist[nr][nc], {nr, nc}});
            }
        }
    }
    if (dist[n - 1][m - 1] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[n - 1][m - 1] << endl;
    }
    return 0;
}