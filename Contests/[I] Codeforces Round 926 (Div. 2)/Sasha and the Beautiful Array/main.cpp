#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, mx = INT_MIN, mn = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    cout << mx - mn << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
