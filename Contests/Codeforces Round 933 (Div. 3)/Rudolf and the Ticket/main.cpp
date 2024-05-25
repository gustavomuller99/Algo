#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, ans = 0;
        cin >> n >> m >> k;
        vector<int> b(n), cnt(2001);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for (int i = 1; i < 2001; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (b[i] < k) ans += cnt[k - b[i]];
        }
        cout << ans << "\n";
    }
}
