#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 1;
        for (int i = n; i > 1; --i) {
            vector<int> inv(n);
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if ((s[j] - '0' + cnt) % 2 != 1) {
                    cnt++;
                    if (j + i - 1 > n - 1) break;
                    else inv[j + i - 1] = -1;
                }
                cnt += inv[j];
                if (j == n - 1) ans = max(ans, i);
            }
        }
        cout << ans << "\n";
    }
}
