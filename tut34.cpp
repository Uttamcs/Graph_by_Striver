//   Find the City With the Smallest Number of Neighbours at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (auto &edge : edges)
    {
        dist[edge[0]][edge[1]] = edge[2];
        dist[edge[1]][edge[0]] = edge[2];
    }
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int ans = INT_MAX, city = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (dist[i][j] <= distanceThreshold)
                count++;
        if (count <= ans)
        {
            ans = count;
            city = i;
        }
    }
    cout << city << endl; 
    return 0;
}