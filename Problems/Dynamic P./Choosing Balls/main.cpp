#include <bits/stdc++.h>
     
    #define ll long long
    using namespace std;
     
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        vector<ll> d(n + 1, -1e12), p(n + 1);
        d[0] = 0;
        ll p1 = 0, p2 = 0;
        for (int j = 0; j < n; ++j) {
            d[c[j]] = max({d[c[j]],
                           d[c[j]] + a[j] * x,
                           (p1 == c[j]) ? (d[p2] + a[j] * y) : (d[p1] + a[j] * y)});
            if (d[p1] <= d[c[j]] || p1 == c[j]) {
                if (p1 != c[j]) p2 = p1, p1 = c[j];
            } else if (d[p2] <= d[c[j]]) {
                p2 = c[j];
            }
            p[c[j]] = true;
        }
        cout << d[p1] << "\n";
    }
}