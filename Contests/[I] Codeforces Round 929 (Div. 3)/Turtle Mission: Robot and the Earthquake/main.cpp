#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m)), d(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    while (!q.empty()) {
        auto p = q.front().first;
        int t = q.front().second;
        q.pop();
        if (d[p.first][p.second] <= t) continue;
        d[p.first][p.second] = t;
        if (p.second == m - 1) continue;
        if (g[(p.first + 1) % n][p.second + 1] != 1)
            q.push({{(p.first + 1) % n, p.second + 1}, t + 1});
        if (g[(p.first + 2) % n][p.second] != 1 && g[(p.first + 1) % n][p.second] != 1)
            q.push({{(p.first + 2) % n, p.second}, t + 1});
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (d[i][m - 1] != INT_MAX) {
            int t = d[i][m - 1];
            int f = (n - 1 + t) % n;
            ans = min(ans, t + min(abs(f - i), abs(n - abs(f - i))));
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
