#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, q, x = INT_MAX;
        cin >> k >> q;
        for (int i = 0; i < k; ++i) {
            int y;
            cin >> y;
            x = min(x, y);
        }
        for (int i = 0; i < q; ++i) {
            int n;
            cin >> n;
            cout << min(n, x - 1) << " ";
        }
        cout << "\n";
    }
}
