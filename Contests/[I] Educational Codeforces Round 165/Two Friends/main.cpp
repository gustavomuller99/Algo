#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        int ans = 3;
        for (int i = 0; i < n; ++i) {
            if (a[a[i]] == i) ans = 2;
        }
        cout << ans << "\n";
    }
}
