#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0, ans;
        a = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x]++;
        }
        for (ans = 0; ans < n; ++ans) {
            if (a[ans] == 0) break;
            if (a[ans] == 1) cnt++;
            if (cnt == 2) break;
        }
        cout << ans << "\n";
    }
}
