#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
int mod = 1e9 + 7;

// https://codeforces.com/gym/344975/problem/F

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(60);
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int k = 0; k < 60; ++k)
                if (a[i] & (1ULL << k)) cnt[k]++;
        }
        ll ans  = 0;
        for (int i = 0; i < n; ++i) {
            ll l = 0, r = 0;
            for (int k = 0; k < 60; ++k) {
                ll p = (1ULL << k) % mod;
                if (a[i] & (1ULL << k)) {
                    l = (l + p * cnt[k]) % mod;
                    r = (r + p * n) % mod;
                } else {
                    r = (r + p * cnt[k]) % mod;
                }
            }
            ans = (ans + l * r) % mod;
        }
        cout << ans << "\n";
    }
}
