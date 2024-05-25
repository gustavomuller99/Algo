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
        }
        int cnt = 0, ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (a[i] == a[0]) cnt++;
            else ans = min(ans, cnt), cnt = 0;
        }
        ans = min(ans, cnt);
        cout << (ans == n ? -1 : ans) << "\n";
    }
}
