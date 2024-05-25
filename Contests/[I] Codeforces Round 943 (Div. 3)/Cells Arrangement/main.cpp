#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= max(2, n - 2); ++i) {
            cout << "1 " << i << "\n";
        }
        if (n > 2) cout << n << " " << n << "\n";
        if (n > 3) cout << n << " " << 2 << "\n";
        cout << "\n";
    }
}
