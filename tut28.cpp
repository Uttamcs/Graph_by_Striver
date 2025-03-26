// Path with minimum effort
// https://leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r = 3, c = 3;
    int arr[r][c] = {{1, 2, 2}, {3, 8, 2}, { 5, 3, 5}};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int dist[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int d = pq.top().first;
        pq.pop();
        if (x == r - 1 && y == c - 1)
        {
            cout << d << endl;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dr[i];
            int ny = y + dc[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                int nd = max(d, abs(arr[nx][ny] - arr[x][y]));
                if (nd < dist[nx][ny])
                {
                    dist[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
                }
            }
        }
    }

    return 0;
}