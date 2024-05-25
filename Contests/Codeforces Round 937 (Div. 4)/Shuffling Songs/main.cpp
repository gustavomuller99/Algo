#include <bits/stdc++.h>

using namespace std;

vector<int> gi, wi;

void solve() {
    int n;
    cin >> n;
    gi = wi = vector<int>(n);
    map<string, int> g, w;
    int cnt = 1;
    auto d = vector<vector<int>>(1 << n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string x, y;
        cin >> x >> y;
        if (g[x] == 0) g[x] = cnt++;
        if (w[y] == 0) w[y] = cnt++;
        gi[i] = g[x];
        wi[i] = w[y];
    }
    for (int i = 0; i < n; ++i) {
        d[1 << i][i] = 1;
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int lst = 0; lst < n; ++lst) {
            if (!d[mask][lst]) continue;
            for (int nxt = 0; nxt < n; ++nxt) {
                if (!(mask & 1 << nxt) && (gi[lst] == gi[nxt] || wi[lst] == wi[nxt])) {
                    d[mask + (1 << nxt)][nxt] = 1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][j]) ans = max(ans, __builtin_popcount(i));
        }
    }
    cout << n - ans << "\n";
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
