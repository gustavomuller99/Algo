#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
vector<ll> a;
ll n, k;

// https://codeforces.com/blog/entry/129027
/* a1 >= .. an = w */
// ans = 1 + n*w + (a1 = w)
// binary search on w (max)
// or: binary search on ans, count the number of card needed (below)

bool f(ll x) {
    ll m = 1 + (x + n - 2) / n, r = (x % n - 1 + n) % n;
    if (r == 0) r += n + 1;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 <= r && a[i] < m) cnt += m - a[i];
        else if (i + 1 > r && a[i] < m - 1) cnt += (m - 1) - a[i];
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end(), greater<>());
        ll l = 1, r = 1e19;
        while (l + 1 < r) {
            ll mid = l + (r - l) / 2;
            if (f(mid)) l = mid;
            else r = mid;
        }
        cout << l << "\n";
    }
}
