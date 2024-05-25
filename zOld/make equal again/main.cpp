#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int l = 0, r = n - 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1 && a[i + 1] == a[i]; ++i) {
        l++;
    }
    for (int i = n - 1; i > 0 && a[i - 1] == a[i]; --i) {
        r--;
    }
    if (l == n - 1) cout << "0\n";
    else if (a[r] == a[l]) cout << r - l - 1 << "\n";
    else {
        cout << min(n - 1 - l, r) << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
