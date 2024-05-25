#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        long long ans = 0, cnt1 = 0, cnt0 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (i && s[i - 1] == '0') {
                    if (cnt1) ans += cnt0 * (cnt1 + 1);
                    cnt0 = 0;
                }
                cnt1++;
            } else {
                cnt0++;
            }
        }
        if (s.back() == '0' && cnt1) ans += cnt0 * (cnt1 + 1);
        cout << ans << "\n";
    }
}
