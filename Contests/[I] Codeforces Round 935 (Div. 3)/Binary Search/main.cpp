#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, xi;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == x) xi = i;
    }
    int l = 0, r = n;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        b[mid] = 1;
        if (a[mid] <= x) l = mid;
        else r = mid;
    }
    if (l == xi) cout << "0\n";
    else if (b[xi] == 0 || (b[xi] && a[l] < x)) {
        cout << "1\n";
        cout << xi + 1 << " " << l + 1 << "\n";
    }
    else {
        int idx;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0 && a[i] < x) idx = i;
        }
        cout << "2\n";
        cout << xi + 1 << " " << l + 1 << "\n";
        cout << xi + 1 << " " << idx + 1 << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
