// Course Schedule - I and II
// I and II have the same approach but the only difference is that in I we have to return true or false and in II we have to return the order of courses to be taken.

#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(n);
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }

    queue<int> q;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for (auto it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
                q.push(it);
        }
    }
    if (res.size() == n)
        return res;
    return {};
}
int main()
{
    int n = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> res = findOrder(n, prerequisites);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}