#include <bits/stdc++.h>

using namespace std;
struct p {
    int cnt, w;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> e;
    vector<pair<p, p>> d(n, {{0, 0},{0, 0}});
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        e.push_back({w, {u, v}});
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < m; ++i) {
        int w = e[i].first, u = e[i].second.first, v = e[i].second.second;
        if (w != d[u].first.w) {
            if (d[u].second.cnt <= d[u].first.cnt) d[u].second = d[u].first;
            d[u].first = {0, w};
        }
        if (w != d[v].first.w) {
            if (d[v].second.cnt <= d[v].first.cnt) d[v].second = d[v].first;
            d[v].first = {0, w};
        }
        d[v].first.cnt = max(d[v].first.cnt, d[u].second.cnt + 1);
    }
    for (int i = 0; i < n; ++i) {
        ans = max({ans, d[i].first.cnt, d[i].second.cnt});
    }
    cout << ans;
}
