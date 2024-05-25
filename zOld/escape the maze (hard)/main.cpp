#include <bits/stdc++.h>
using namespace std;
vector<pair<int, vector<int>>> g;
vector<int> vis;
int dfs(int n = 0, int f = -1, int d = 0) {
    if(d >= g[n].first) return 1;
    if(n != 0 && g[n].second.size() == 1) return -1;
    int r = 0;
    for(int adj: g[n].second) {
        if(adj == f) continue;
        int p = dfs(adj, n, d+1);
        if(p == -1) return p;
        r += p;
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        g = vector<pair<int, vector<int>>> (n); vis = vector<int>(n);
        queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            int x; cin>>x; x--; q.push({x, 0});
        }
        for (int i = 0; i < n-1; ++i) {
            int u, v; cin>>u>>v; u--,v--;
            g[u].second.push_back(v),
            g[v].second.push_back(u);
        }
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            if(vis[p.first]) continue;
            vis[p.first] = true;
            g[p.first].first = p.second;
            for(int adj : g[p.first].second) {
                q.push({adj, p.second + 1});
            }
        }
        cout << dfs() << "\n";
    }
}
