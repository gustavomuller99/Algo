#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int f = -1, cnt = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] && f == -1) f = i;
            if (a[i]) cnt++;
        }
        for (int i = f; i < n && cnt; ++i) {
            if (a[i]) cnt--;
            else ans++;
        }
        cout << ans << "\n";
    }
}
