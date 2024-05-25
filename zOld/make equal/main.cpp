#include <bits/stdc++.h>

using namespace std;

string solve() {
    int n, s = 0, r = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    s /= n;
    for (int i = 0; i < n; ++i) {
        if (a[i] > s) r += a[i] - s;
        if (a[i] < s && r < s - a[i]) return "NO\n";
        if (a[i] < s) r -= s - a[i];
    }
    if (r > 0) return "NO\n";
    else return "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve();
    }
}
