#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> t;
vector<ll> w;

pair<ll,ll> dfs(int u, int f = -1) {
    pair<ll, ll> r;
    if(t[u].size() == 1) r = {w[u] > 0 ? w[u] : 0, w[u] < 0 ? -w[u] : 0};
    for(int adj: t[u]) {
        if(adj != f) {
            auto k = dfs(adj, u);
            r.first = max(r.first, k.first);
            r.second = max(r.second, k.second);
        }
    }
    ll c = w[u] - r.first + r.second;
    if(c >= 0) return {r.first + c, r.second};
    else return {r.first, r.second - c};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    t.resize(n); w.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        t[u].push_back(v), t[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) cin>>w[i];
    auto r = dfs(0);
    cout << r.first + r.second + abs((w[0] - r.first + r.second));
}
