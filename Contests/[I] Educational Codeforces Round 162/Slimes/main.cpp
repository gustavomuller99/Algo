#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 2), sum(n + 2), p(n + 2), ans(n + 2, LLONG_MAX);

        for (int i = 1; i <= n; ++i) cin >> a[i];

        for (int k = 0; k < 2; ++k) {
            for (int i = 1; i <= n; ++i) sum[i] = a[i], sum[i] += sum[i - 1];
            p = vector<ll>(n + 2, -1);
            for (int i = 1; i <= n; ++i) {
                int l = 1, r = i;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (sum[i - 1] - sum[mid - 1] > a[i] && p[i - 1] != p[mid]) {
                        ans[i] = min(ans[i], (ll) i - mid);
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                if (a[i - 1] > a[i]) ans[i] = 1;
                p[i] = (a[i] != a[i - 1] ? i : p[i - 1]);
            }
            reverse(a.begin(), a.end());
            reverse(ans.begin(), ans.end());
        }
        for (int i = 1; i <= n; ++i) {
            cout << (ans[i] == LLONG_MAX ? -1 : ans[i]) << " ";
        }
        cout << "\n";
    }
}