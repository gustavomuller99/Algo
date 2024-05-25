#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<pair<ll, ll>> a(n);
        vector<ll> b(n);
        vector<bool> c(n);
        for (int i = 0; i < n; ++i) a[i].second = i, cin >> a[i].first, b[i] = a[i].first;
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll curr = a[i].first, in = a[i].second;
            if(curr >= p) break;
            while (in > 0) {
                if (c[in - 1]) break;
                if (b[in - 1] % curr == 0) {
                    ans += curr;
                    c[in - 1] = true;
                } else break;
                in--;
            }
            in = a[i].second;
            while (in < n - 1) {
                if (c[in]) break;
                if (b[in + 1] % curr == 0) {
                    ans += curr;
                    c[in] = true;
                } else break;
                in++;
            }
        }
        for (int i = 0; i < n - 1; ++i) if (!c[i]) ans += p;
        cout << ans << "\n";
    }
}
