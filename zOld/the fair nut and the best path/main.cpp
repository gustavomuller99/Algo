#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<ll, ll>>> t;
vector<pair<ll, ll>> d;
vector<ll> w;
ll ans = 0;

void dfs1(int u, int p = -1) {
    d[u].first = w[u]; d[u].second = w[u];
    for(auto adj: t[u]) {
        if(adj.first != p) {
            dfs1(adj.first, u);
            if(d[adj.first].first  - adj.second + w[u] > d[u].first)
                d[u].second = d[u].first, d[u].first = d[adj.first].first - adj.second + w[u];
            else if(d[adj.first].first  - adj.second + w[u] > d[u].second)
                d[u].second = d[adj.first].first - adj.second + w[u];
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n; t.resize(n); w.resize(n); d.resize(n);
    for (int i = 0; i < n; ++i) cin>>w[i];
    for (int i = 0; i < n-1; ++i) {
        int u, v, c; cin>>u>>v>>c; u--, v--;
        t[u].emplace_back(v, c), t[v].emplace_back(u, c);
    }
    dfs1(0);
    for (int i = 0; i < n; ++i) {
        ans = max(ans, d[i].first + d[i].second - w[i]);
    }
    cout << ans;
}
