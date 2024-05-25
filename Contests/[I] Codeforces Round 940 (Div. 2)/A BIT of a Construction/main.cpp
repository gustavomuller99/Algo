#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, p = 1;
        cin >> n >> k;
        while (p <= k) p *= 2;
        p /= 2;
        if (n == 1) cout << k << "\n";
        else {
            cout << (p - 1) << " " << k - (p - 1) << " ";
            for (int i = 0; i < n - 2; ++i) cout << 0 << " ";
            cout << "\n";
        }
    }
}
