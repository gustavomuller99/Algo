#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n + 1), cnt(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] == 1) cnt[i]++;
            a[i] += a[i - 1], cnt[i] += cnt[i - 1];
        }
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            ll s = (r - l + 1) + (cnt[r] - cnt[l - 1]);
            if (s <= (a[r] - a[l - 1]) && l != r) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
