#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> a;
vector<map<int, int>> d;
long long ans = 0;

void dfs(int u, int p = -1) {
    int best = -1;
    for (int adj: g[u]) {
        if (adj != p) {
            dfs(adj, u);
            if (best == -1 || d[best].size() < d[adj].size()) best = adj;
        }
    }
    for (int adj: g[u]) {
        if (adj != p && adj != best) {
            for (auto c: d[adj]) {
                if (c.first != a[u]) {
                    ans += (1ll) * c.second * d[best][c.first];
                }
                d[best][c.first] += c.second;
            }
        }
    }
    if (best != -1) swap(d[u], d[best]);
    ans += d[u][a[u]];
    d[u][a[u]] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a = vector<int>(n);
        g = vector<vector<int>>(n);
        d = vector<map<int, int>>(n + 1);
        ans = 0;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v), g[v].push_back(u);
        }
        dfs(0, 0);
        cout << ans << "\n";
    }
}
