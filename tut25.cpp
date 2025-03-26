// Dijkstra's Algorithm

// using priority_queue (min heap)


// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<vector<pair<int,int>>> adj = {{{1,1},{2,6}},{{0,1},{2,3},{3,2}},{{0,6},{1,3},{3,1}},{{1,2},{2,1},{4,2}},{{3,2}}};
//     int n = 5;
//     vector<int> dist(n,INT_MAX);
//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//     int src = 0;
//     dist[src] = 0;
//     pq.push({0,src});
//     while(!pq.empty())
//     {
//         int node = pq.top().second;
//         int distance = pq.top().first;
//         pq.pop();
//         for(auto it : adj[node])
//         {
//             if(distance + it.second < dist[it.first])
//             {
//                 dist[it.first] = distance + it.second;
//                 pq.push({dist[it.first],it.first});
//             }
//         }
//     }
//     for(int i = 0; i < n; i++)
//     {
//         cout << dist[i] << " ";
//     }
//     return 0;
// }





// using set
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<pair<int, int>>> adj = {{{1, 1}, {2, 6}}, {{0, 1}, {2, 3}, {3, 2}}, {{0, 6}, {1, 3}, {3, 1}}, {{1, 2}, {2, 1}, {4, 2}}, {{3, 2}}};
    int n = 5;
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> st;
    int src = 0;
    dist[src] = 0;
    st.insert({0, src});
    while (!st.empty())
    {
        auto it = st.begin();
        int node = it->second;
        int distance = it->first;
        st.erase(it);
        for (auto it : adj[node])
        {
            if (distance + it.second < dist[it.first])
            {
                if (dist[it.first] != INT_MAX)
                    st.erase({dist[it.first], it.first});
                dist[it.first] = distance + it.second;
                st.insert({dist[it.first], it.first});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}