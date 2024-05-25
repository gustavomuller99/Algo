#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

void solve() {
    ll m, n, ans = ULLONG_MAX, sum = 0;
    cin >> n >> m;
    m--;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = n - 1; i >= 0; --i) {
        if (i <= m) ans = min(ans, sum + a[i]);
        sum += min(a[i], b[i]);
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
