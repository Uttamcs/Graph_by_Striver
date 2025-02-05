// Flood Fill

#include <bits/stdc++.h>
using namespace std;
void dfs(int r, int c, vector<vector<int>> &ans, vector<vector<int>> image, int iniCol, int newCol)
{
    ans[r][c] = newCol;
    int n = image.size();
    int m = image[0].size();
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int newR = r + delRow[i];
        int newC = c + delCol[i];
        if (newR >= 0 && newR < n && newC >= 0 && newC < m && image[newR][newC] == iniCol && ans[newR][newC] != newCol)
        {
            dfs(newR, newC, ans, image, iniCol, newCol);
        }
    }
}
int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    int n = image.size();
    int m = image[0].size();
    int iniCol = image[sr][sc];
    vector<vector<int>> ans = image;
    dfs(sr, sc, ans, image, iniCol, color);
    for(auto it: ans)
    {
        for(auto i: it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}