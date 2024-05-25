#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, sum = 0; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = (3 - (sum % 3)) % 3;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, (3 - (sum - a[i]) % 3) % 3 + 1);
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
