#include <bits/stdc++.h>

using namespace std;

/*
 * b * gcd(a, b) = ka + kb
 * gcd(a, b) = d
 * a = pd, b = qd, gcd(p, q) = 1
 * (a + b) | (b * gcd(a, b)) --> (pd + qd) | (qd^2) --> (p + q) | (qd)
 * gcd(p + q, q) = gcd(p, q) = 1 --> (p + q) |\ q --> (p + q) | d
 * --> gcd(p, q) = 1 ^ (p + q) | d => d = k * (p + q)
 * --> a = pd, p^2 <= n,
 * --> b = qd, q^2 <= m
 * --> a = p * k * (p + q) <= n --> k <= n / (p * (p + q));
 * --> b = q * k * (p + q) <= m --> k <= m / (q * (p + q));
 * how many k for each (p, q)?
 */

#define ll unsigned long long

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        for (ll p = 1; p * p <= n; ++p) {
            for (ll q = 1; q * q <= m; ++q) {
                if (gcd(p, q) == 1) {
                    ans += min(n / (p * (p + q)), m / (q * (p + q)));
                }
            }
        }
        cout << ans << "\n";
    }
}
