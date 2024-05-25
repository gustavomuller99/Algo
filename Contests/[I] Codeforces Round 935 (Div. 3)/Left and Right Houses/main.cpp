#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int tot1 = 0, tot0 = 0, ans = -1, cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') tot0++;
            else tot1++;
        }
        if ((tot1 - cnt1) < (n + 1) / 2) ans = -2;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') cnt0++;
            else cnt1++;
            int res = i + 1;
            if (cnt0 >= (res + 1) / 2 && (tot1 - cnt1) >= (n - res + 1) / 2) {
                if (abs(n - 2 * (i + 1)) < abs(n - 2 * (ans + 1))) ans = i;
            }
        }
        cout << ans + 1 << "\n";
    }
}
