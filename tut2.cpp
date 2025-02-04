// // Connnected Graph

// #include<bits/stdc++.h>
// using namespace std;
// vector<int> bfs(int n, vector<int> adj[]){
//     vector<int> ans;
//     vector<int> vis(n+1,0);
//     for(int i=1;i<=n;i++){
//         if(!vis[i]){
//             queue<int> q;
//             q.push(i);
//             vis[i]=1;
//             while(!q.empty()){
//                 int node = q.front();
//                 q.pop();
//                 ans.push_back(node);
//                 for(auto it:adj[node]){
//                     if(!vis[it]){
//                         q.push(it);
//                         vis[it]=1;
//                     }
//                 }
//             }
//         }
//     }
//     return ans;
// }
// int main(){
//     int n,e;
//     cin>>n>>e;
//     vector<int> adj[n+1];
//     for(int i=0;i<e;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int>ans = bfs(n,adj);
//     for(auto it:ans){
//         cout<<it<<" ";
//     }
//     return 0;
// }



// DFS 
#include<bits/stdc++.h>
using namespace std;    
vector<int> ans;
vector<int>dfs(int n , vector<int> adj[], int s, vector<int>& vis){
    vis[s]=1;
    ans.push_back(s);
    for(auto it: adj[s]){
        if(!vis[it]){
            dfs(n, adj, it, vis);
        }
    }
    return ans;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n+1];
    vector<int> vis(n+1, 0);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int start = 1;
    vector<int>ans = dfs(n,adj,start, vis);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}