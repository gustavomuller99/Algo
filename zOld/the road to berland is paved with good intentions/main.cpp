#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> g;
vector<bool> vis;
vector<int> ans, col;
void dfs(int i, int c = 0) {
    if(c) ans.push_back(i);
    col[i] = c;
    vis[i] = true;
    for(auto adj : g[i]) {
        if(vis[adj.first]) {
            if(c ^ adj.second ^ col[adj.first] ^ 1) cout << "Impossible", exit(0);
        }
        else dfs(adj.first, c ^ adj.second ^ 1);
    }
}
int main() {
    int n, m; cin>>n>>m;
    g.resize(n); vis.resize(n); col.resize(n);
    for (int i = 0; i < m; ++i) {
        int u,v,c; cin>>u>>v>>c; u--,v--;
        g[u].push_back({v, c}), g[v].push_back({u, c});
    }
    for (int i = 0; i < n; ++i) if(!vis[i]) dfs(i);
    cout << ans.size() << "\n";
    for (int an : ans) {
        cout << an + 1 << " ";
    }
}
