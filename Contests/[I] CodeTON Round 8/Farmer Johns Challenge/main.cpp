#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k == n || k == 1) {
            for (int i = 0; i < n; ++i) {
                cout << 1 + i * (k == 1) << " ";
            }
            cout << "\n";
        } else cout << "-1\n";
    }
}
