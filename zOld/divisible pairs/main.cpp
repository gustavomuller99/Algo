#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    ll ans = 0;
    ll n, x, y;
    map<pair<ll, ll>, int> m;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        ans += m[{(x - a[i] % x) % x,
                 (y - (-a[i]) % y) % y}];
        m[{a[i] % x, a[i] % y}]++;
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
