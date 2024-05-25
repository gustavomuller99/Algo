#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<ll>> b(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b[abs(x)].push_back(a[i]);
    }
    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
        tot += k;
        for (ll x : b[i]) {
            if (x > tot) {
                cout << "NO\n";
                return;
            }
            tot -= x;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
