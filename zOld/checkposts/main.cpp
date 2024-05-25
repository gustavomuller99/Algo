#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g, gt;
vector<int> c, used, order, comp;

void dfs1(int u) {
    used[u] = true;
    for(auto v : g[u]) if(!used[v]) dfs1(v);
    order.push_back(u);
}

int dfs2(int u) {
    int r = c[u];
    used[u] = false;
    comp.push_back(u);
    for(auto v: gt[u]) if(used[v]) r = min(r, dfs2(v));
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n, m, cost = 0, ans = 1, mod = 1e9+7; cin>>n;
    c.resize(n); g.resize(n); gt.resize(n); used.resize(n, 0);
    for (int i = 0; i < n; ++i) cin>>c[i];
    cin>>m;
    for (int i = 0; i < m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) if(!used[i]) dfs1(i);
    reverse(order.begin(), order.end());
    for (auto v : order) {
        if(used[v]) {
            int r = dfs2(v), am = 0;
            for(auto u : comp) {
                if(c[u] == r) am++;
            }
            cost += r;
            ans *= am; ans %= mod;
            comp.clear();
        }
    }
    cout << cost << " " << ans;
}
