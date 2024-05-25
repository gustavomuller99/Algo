#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g, gt;
vector<int> used, order, comp, scc;
int k = 1;

void dfs1(int u) {
    used[u] = true;
    for (auto v : g[u]) if (!used[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u, int c) {
    scc[u] = c;
    used[u] = false;
    comp.push_back(u);
    for (auto v: gt[u]) if (used[v]) dfs2(v, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, h;
    cin >> n >> m >> h;
    g.resize(n);
    gt.resize(n);
    used.resize(n, 0);
    scc.resize(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if ((c[u] + 1) % h == c[v]) {
            g[u].push_back(v);
            gt[v].push_back(u);
        }
        if ((c[v] + 1) % h == c[u]) {
            g[v].push_back(u);
            gt[u].push_back(v);
        }
    }
    for (int i = 0; i < n; ++i) if (!used[i]) dfs1(i);
    reverse(order.begin(), order.end());
    vector<int> ans;
    for (int i = 0; i < n; ++i) ans.push_back(i);
    for (auto v : order) {
        if (used[v]) {
            dfs2(v, ++k);
            bool sink = true;
            for (int u : comp) {
                for (int adj: g[u]) {
                    if (scc[adj] != k) sink = false;
                }
            }
            if (sink && comp.size() < ans.size()) ans = comp;
            comp.clear();
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " ";
    }
}