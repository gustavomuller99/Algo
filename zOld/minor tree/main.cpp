#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

vector<vector<pair<ll, ll>>> g;
set<ll> ans;
vector<bool> d;
int mx = 0;

bool v(ll w, int b) {
    if (w & (1ll << b)) return false;
    for (int i = 29; i > b; --i)
        if(!ans.count(i) && (w & (1ll << i))) return false;
    return true;
}

int dfs(ll u, int b) {
    d[u] = true;
    int r = 1;
    for (auto adj : g[u]) {
        if(v(adj.second, b) && !d[adj.first]) r += dfs(adj.first, b);
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        g = vector<vector<pair<ll, ll>>> (n);
        mx = 0;
        ans = set<ll> ();
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            g[u].push_back({v, w}), g[v].push_back({u, w});
            mx = max(mx, w);
        }
        int b = 29;
        while (b >= 0) {
            d = vector<bool> (n);
            if (dfs(0, b) != n) ans.insert(b);
            b--;
        }
        unsigned long long s = 0;
        for (ll x : ans) s += (1ll << x);
        cout << s << "\n";
    }
}
