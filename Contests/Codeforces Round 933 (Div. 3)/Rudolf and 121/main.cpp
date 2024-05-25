#include <bits/stdc++.h>

using namespace std;

string solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 2; ++i) {
        if (a[i] < 0) return "NO\n";
        if (a[i] > 0) a[i + 1] -= a[i] * 2, a[i + 2] -= a[i], a[i] = 0;
    }
    if (a[n-2] != 0 || a[n-1] != 0) return "NO\n";
    return "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve();
    }
}
