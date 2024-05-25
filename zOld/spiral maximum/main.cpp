#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int a[n][m], s[n][m], d[n][m], ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            s[i][j] = a[i][j];
            if (i) s[i][j] += s[i - 1][j];
            if (j) s[i][j] += s[i][j - 1];
            if (i && j) s[i][j] -= s[i - 1][j - 1];
            if (i > 1 && j > 1) {
                d[i][j] = a[i][j] + a[i - 1][j] + a[i - 2][j] + a[i - 2][j - 1] + a[i - 2][j - 2] + a[i][j - 1] +
                             a[i][j - 2];
                ans = max(ans, d[i][j]);
            }
        }
    }
    for (int k = 5; k <= min(n, m); k += 2) {
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                if (i > k - 2 && j > k - 2) {
                    d[i][j] = s[i][j] - d[i - 1][j - 1] - a[i - k + 2][j - k + 1];
                    if (i > k - 1) d[i][j] -= s[i - k][j];
                    if (j > k - 1) d[i][j] -= s[i][j - k];
                    if (i > k - 1 && j > k - 1) d[i][j] += s[i - k][j - k];
                    ans = max(ans, d[i][j]);
                }
            }
        }
    }
    cout << ans;
}
