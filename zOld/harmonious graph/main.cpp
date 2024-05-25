#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> vis;
vector<int> b, e;
int dfs(int u, int mx) {
    vis[u] = true;
    mx = max(mx, u);
    for(int adj : g[u]) {
        if(!vis[adj]) mx = dfs(adj, mx);
    }
    return mx;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin>>n>>m;
    g.resize(n);
    vis.resize(n);
    b.resize(n); e.resize(n);
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if(!vis[i]) {
            int mx = dfs(i,i);
            b[i] = 1, e[mx] = 1;
        }
    }
    int cc = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        cc += b[i];
        if(b[i] && cc > 1) ans++;
        cc -= e[i];
    }
    cout << ans;
}
