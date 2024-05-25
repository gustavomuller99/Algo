#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    r[1] = 1; l[n - 2] = 1;
    for (int i = 2; i < n; ++i) {
        r[i] = (a[i - 1] - a[i - 2] > a[i] - a[i - 1]) ? 1 : a[i] - a[i - 1];
        r[i] += r[i - 1];
    }
    for (int i = n - 3; i >= 0; --i) {
        l[i] = (a[i + 2] - a[i + 1] > a[i + 1] - a[i]) ? 1 : a[i + 1] - a[i];
        l[i] += l[i + 1];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) cout << l[y] - l[x] << "\n";
        else cout << r[y] - r[x] << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
