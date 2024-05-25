#include <bits/stdc++.h>

using namespace std;

/*
 * https://codeforces.com/contest/1967/problem/B1
 * a + b = k * b * gcd(a, b) -> b | a
 * a + b = k * b * b
 * a = k*b^2 - b
 * */

#define ll unsigned long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        for (int i = 1; i <= m; ++i) {
            ll l = 0, r = n + 1;
            while (l + 1 < r) {
                ll mid = (l + r) / 2;
                if (mid * i * i - i > n) r = mid;
                else l = mid;
            }
            ans += l;
        }
        cout << ans << "\n";
    }
}
