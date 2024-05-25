#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> t;
vector<ll> w, ms;
ll ans = LLONG_MIN;

ll dfs(int u, int f = -1) {
    ll r = 0;
    vector<ll> m(2, LLONG_MIN);
    for(int adj : t[u]) {
        if(adj != f) {
            r += dfs(adj, u);
            ms[u] = max(ms[u], ms[adj]);
            if(ms[adj] > m[0]) m[1] = m[0], m[0] = ms[adj];
            else if(ms[adj] > m[1]) m[1] = ms[adj];
        }
    }
    if(t[u].size() > 2 || (t[0].size() > 1 && u == 0))
        ans = max(ans, m[0] + m[1]);
    r += w[u];
    if(r > ms[u]) ms[u] = r;
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    t.resize(n); w.resize(n); ms.resize(n, LLONG_MIN);
    for (int i = 0; i < n; ++i) cin>>w[i];
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        t[u].push_back(v); t[v].push_back(u);
    }
    dfs(0);
    if(ans == LLONG_MIN) cout << "Impossible";
    else cout << ans;
}
