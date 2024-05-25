#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    cout << ((k + 1) / 2 + (k == (4 * n - 2))) << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
