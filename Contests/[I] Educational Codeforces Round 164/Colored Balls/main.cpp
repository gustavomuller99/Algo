#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll MOD = 998244353;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), cnt(5001);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        for (ll k = cnt.size() - 1; k > 0; --k) {
            if (cnt[k]) {
                if ((k + a[i] + 1) / 2 < a[i]) ans = (ans + a[i] * cnt[k]) % MOD;
                else ans = (ans + ((k + a[i] + 1) / 2) * cnt[k]) % MOD;
            }
            if (k - a[i] >= 0 && cnt[k - a[i]]) {
                cnt[k] += cnt[k - a[i]];
                cnt[k] %= MOD;
            }
            if (k == a[i]) {
                cnt[k]++;
                cnt[k] %= MOD;
            }
        }
        ans = (ans + a[i]) % MOD;
    }
    cout << ans;
}
