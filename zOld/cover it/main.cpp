#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g, p;
vector<bool> vis;
void dfs(int u=0, int pt=0) {
    vis[u] = true;
    p[pt].push_back(u);
    for(int adj : g[u]) {
        if(vis[adj]) continue;
        dfs(adj, !pt);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,m; cin>>n>>m;
        g = vector<vector<int>>(n);
        p = vector<vector<int>>(2);
        vis = vector<bool>(n);
        for (int i = 0; i < m; ++i) {
            int u,v; cin>>u>>v; u--,v--;
            g[u].push_back(v), g[v].push_back(u);
        }
        dfs();
        int index = (p[0].size() < p[1].size() ? 0 : 1);
        cout << p[index].size() << "\n";
        for (int i : p[index]) cout << i + 1 << " ";
        cout << "\n";
    }
}
