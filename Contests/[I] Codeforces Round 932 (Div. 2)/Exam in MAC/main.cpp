#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

// https://codeforces.com/contest/1935/problem/D

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, c, ans = 0;
        cin >> n >> c;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ans = (c + 1) * (c) / 2 + c + 1;
        vector<int> p(2);
        for (int i = 0; i < n; ++i) {
            ans -= (a[i] / 2) + (c - a[i] + 1);
            ans += p[a[i] % 2];
            p[a[i] % 2]++;
        }
        cout << ans << "\n";
    }
}
