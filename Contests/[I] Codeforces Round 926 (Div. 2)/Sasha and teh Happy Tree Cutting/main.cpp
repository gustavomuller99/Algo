#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> t;
vector<pair<int, int>> pairs;
vector<int> path;
vector<int> dp;
map<pair<int, int>, int> m;

bool dfs(int u, int v, int f = -1) {
    if (u == v) {
        path.push_back(u);
        return true;
    }
    bool r = false;
    for (int adj: t[u]) {
        if (adj == f) continue;
        r |= dfs(adj, v, u);
    }
    if (r) path.push_back(u);
    return r;
}

void solve() {
    int n, k;
    cin >> n;
    m = map<pair<int, int>, int>();
    t = vector<vector<int>>(n);
    pairs = vector<pair<int, int>>();
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        t[u].push_back(v), t[v].push_back(u);
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        pairs.emplace_back(u, v);
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = i + 1; j < dp.size(); ++j) {
            dp[i | j] = min(dp[i | j], dp[i] + dp[j]);
        }
    }
    cout << dp[(1 << k) - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
