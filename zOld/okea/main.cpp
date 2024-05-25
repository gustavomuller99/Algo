#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int p = ((n / 2 + n % 2) * k - 1) * 2 + 1;
        if (n * k < p) cout << "NO\n";
        else {
            cout << "YES\n";
            int l = 1, r = 2;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < k; ++j) {
                    if (i % 2 == 0) cout << l << " ", l += 2;
                    else cout << r << " ", r += 2;
                }
                cout << "\n";
            }
        }
    }
}
