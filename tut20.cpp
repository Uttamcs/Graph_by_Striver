// Alien Dictionary

#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int v, vector<int> adj[])
{
    vector<int> indeg(v, 0);
    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            indeg[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node]) {
            indeg[it]--;
            if (indeg[it] == 0) {
                q.push(it);
            }
        }
    }
    return topo;
};

void solve(vector<string> &dict, string &ans)
{
    int n = dict.size();
    vector<int> adj[26];
    vector<bool> visited(26, false);

    for (string s : dict)
    {
        for (int i = 0; i < s.size(); i++)
        {
            visited[s[i] - 'a'] = true;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        bool find = false;

        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                find = true;
                break;
            }
        }

        if (!find && s1.size() > s2.size())
        {
            cout << "Invalid Input" << endl;
            return;
        }
    }

    vector<int> topo = topoSort(26, adj);

    for (auto it : topo)
    {
        if (visited[it])
        {
            ans += char(it + 'a');
        }
    }
}
int main()
{
    vector<string> dict = { "cb", "cba", "a", "bc"};
    string ans = "";
    solve(dict, ans);
    cout << ans << endl;
    return 0;
}