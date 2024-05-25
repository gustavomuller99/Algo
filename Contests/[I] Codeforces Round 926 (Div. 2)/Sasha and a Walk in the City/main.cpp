#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

ll mod = 998244353;
vector<vector<int>> t;
vector<ll> d;

void dfs(int i = 0, int f = -1) {
    ll sum = 1;
    for (auto adj: t[i]) {
        if (adj == f) continue;
        dfs(adj, i);
        sum = (sum * (d[adj] + 1)) % mod;
    }
    d[i] = sum;
}

void solve() {
    int n;
    cin >> n;
    t = vector<vector<int>>(n);
    d = vector<ll>(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        t[u].push_back(v), t[v].push_back(u);
    }
    dfs();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + d[i]) % mod;
    }
    cout << (ans + 1) % mod << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
