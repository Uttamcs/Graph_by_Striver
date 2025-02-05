// Detect a cycle in Unidirected Graph

// // Using BFS

// #include <bits/stdc++.h>
// using namespace std;

// bool detect(int src, vector<vector<int>> adj, vector<int> &vis)
// {
//     vis[src] = 1;
//     queue<pair<int, int>> q;
//     q.push({src, -1});
//     while (!q.empty())
//     {
//         int node = q.front().first;
//         int parent = q.front().second;
//         q.pop();

//         for (auto nbr : adj[node])
//         {
//             if (!vis[nbr])
//             {
//                 vis[nbr] = 1;
//                 q.push({nbr, node});
//             }
//             else if (parent != nbr)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// int main()
// {
//     vector<vector<int>> adj;
//     adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
//     int n = adj.size();
//     vector<int> vis(n, 0);
//     bool ans = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//         {
//             if (detect(i, adj, vis))
//             {
//                 ans = true;
//                 break;
//             }
//         }
//     }
//     if (ans)
//     {
//         cout << "Cycle Detected" << endl;
//     }
//     else
//     {
//         cout << "Cycle Not Detected" << endl;
//     }
//     cout << endl;
//     return 0;
// }




// Using DFS
#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int parent, vector<vector<int>> adj, vector<int> &vis)
{
    vis[node] = 1;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            if (dfs(nbr, node, adj, vis) == true)
            {
                return true;
            }
        }
        else if (parent != nbr)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> adj;
    adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    int n = adj.size();
    vector<int> vis(n, 0);

    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis) == true)
            {
                ans = true;
                break;
            }
        }
    }
    if (ans)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "Cycle Not Detected" << endl;
    }
    return 0;
}