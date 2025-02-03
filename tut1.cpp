// Representation of Graph


// 1. Matrix Method

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     int adj[n+1][n+1];
//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u][v]=1;
//         adj[v][u]=1;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cout<<adj[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// 2. Adjacency List Method

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<int> adj[n+1];
//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         cout<<i<<"->";
//         for(int j=0;j<adj[i].size();j++)
//         {
//             cout<<adj[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// Weighted Graph
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j].first << " " << adj[i][j].second << " ";
        }
        cout << endl;
    }
    return 0;
}