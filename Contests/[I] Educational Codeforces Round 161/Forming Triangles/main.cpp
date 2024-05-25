#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

void solve() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i <= n; ++i) {
        if (a[i] > 2) ans += a[i] * (a[i] - 1) * (a[i] - 2) / 6;
        if (i) {
            ans += (a[i] * (a[i] - 1) / 2) * (a[i - 1]);
            a[i] += a[i - 1];
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
