#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n + 1), b(n);
    vector<vector<pair<int, ll>>> d(n + 1, vector<pair<int, ll>>(k + 1, {0, ULLONG_MAX}));
    for (int i = 0; i < n; ++i) cin >> a[i];
    a[n] = l;
    for (int i = 0; i < n; ++i) cin >> b[i];
    d[1][0] = {b[0], (a[1] - a[0]) * b[0]};
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            if (d[i][j].first != 0 && d[i + 1][j].second > d[i][j].second + (a[i + 1] - a[i]) * b[i])
                d[i + 1][j] = {b[i], d[i][j].second + (a[i + 1] - a[i]) * b[i]};
            if (j < k && d[i][j].first != 0 && d[i + 1][j + 1].second > d[i][j].second + (a[i + 1] - a[i]) * d[i][j].first)
                d[i + 1][j + 1] = {d[i][j].first, d[i][j].second + (a[i + 1] - a[i]) * d[i][j].first};
        }
    }
    ll ans = INT_MAX;
    for (int i = 0; i < k + 1; ++i) ans = min(ans, d[n][i].second);
    cout << ans;
}
