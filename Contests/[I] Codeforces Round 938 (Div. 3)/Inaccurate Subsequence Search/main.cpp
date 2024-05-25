#include <bits/stdc++.h>

using namespace std;

int cnt[1000005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, ans = 0;
        cin >> n >> m >> k;
        memset(cnt, 0, sizeof(cnt));
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];
        for (int i = 0; i < m; ++i) {
            cnt[b[i]]++;
        }
        for (int i = 0; i < m; ++i) {
            if (cnt[a[i]] > 0) k--;
            cnt[a[i]]--;
        }
        if (k <= 0) ans++;
        for (int i = m; i < n; ++i) {
            if (cnt[a[i]] > 0) k--;
            cnt[a[i]]--;
            if (cnt[a[i - m]] >= 0) k++;
            cnt[a[i - m]]++;
            if (k <= 0) ans++;
        }
        cout << ans << "\n";
    }
}
