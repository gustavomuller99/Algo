#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        int ans = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            while (ans < n - 1 && a[i] > b[ans]) ans++;
            if (a[i] <= b[ans]) ans--;
        }
        cout << ans + 1 << "\n";
    }
}
