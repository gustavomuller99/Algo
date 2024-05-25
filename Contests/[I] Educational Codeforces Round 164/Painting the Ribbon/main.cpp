#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (m * (n - k - 1) < n) cout << "NO\n";
        else cout << "YES\n";
    }
}
