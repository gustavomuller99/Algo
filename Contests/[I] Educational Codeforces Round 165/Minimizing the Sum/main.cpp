#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1969/problem/C

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        vector<vector<ll>> d(n + 1, vector<ll>(k + 1, 1e18));
        for (int i = 0; i < n; ++i) cin >> a[i];
        d[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                ll m = 1e18;
                for (int l = 0; l + j <= k && i + l < n; ++l) {
                    m = min(m, a[i + l]);
                    d[i + l + 1][j + l] = min(d[i + l + 1][j + l], d[i][j] + m * (l + 1));
                }
            }
        }
        cout << *min_element(d[n].begin(), d[n].end()) << '\n';
    }
}
