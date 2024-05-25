#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mp;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        mp[c].push_back(u), mp[c].push_back(v);
    }
    vector<int> vis(n + mp.size() + 1);
    vector<vector<int>> g(n + mp.size() + 1);
    int b, e, sh = 1;
    for (const auto &x : mp) {
        for (int adj: x.second) {
            g[adj].push_back(n + sh);
            g[n + sh].push_back(adj);
        }
        sh++;
    }
    cin >> b >> e;
    queue<pair<int, int>> q;
    q.push({b, 0});
    while (!q.empty()) {
        auto qt = q.front();
        q.pop();
        if (qt.first == e) {
            cout << qt.second / 2 << "\n";
            return;
        }
        vis[qt.first] = true;
        for (int adj: g[qt.first]) {
            if (!vis[adj]) {
                vis[adj] = true;
                q.push({adj, qt.second + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
