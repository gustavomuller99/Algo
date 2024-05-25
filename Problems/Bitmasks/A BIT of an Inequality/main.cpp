#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1957/problem/D

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans = 0;
        cin >> n;
        vector<int> a(n + 2);
        int suff[n + 3][32][2];
        int pref[n + 3][32][2];
        memset(suff, 0, sizeof suff);
        memset(pref, 0, sizeof pref);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int j = 0; j < 32; ++j) {
            for (int i = 1; i <= n; ++i) {
                bool set = (a[i] & (1 << j));
                for (int k = 0; k < 2; ++k) {
                    pref[i][j][k] = (set == k) + pref[i - 1][j][set ^ k];
                }
            }
            for (int i = n; i >= 1; --i) {
                bool set = (a[i] & (1 << j));
                for (int k = 0; k < 2; ++k) {
                    suff[i][j][k] = (set == k) + suff[i + 1][j][set ^ k];
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            int idx = -1;
            for (int j = 0; j < 32; ++j) {
                if (a[i] & 1 << j) idx = j;
            }
            ans += 1ll * (pref[i - 1][idx][1]) * (1 + suff[i + 1][idx][0]);
            ans += 1ll * (1 + pref[i - 1][idx][0]) * (suff[i + 1][idx][1]);
        }
        cout << ans << "\n";
    }
}
