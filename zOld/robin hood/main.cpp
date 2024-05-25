#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

vector<ll> h, l;
int n, k;

bool f1(ll x) {
    ll cnt = 0;
    for (int i = 0; i < h.size(); ++i) {
        if (h[i] > x) cnt += h[i] - x;
    }
    return cnt <= k;
}

bool f2(ll x) {
    ll cnt = 0;
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] < x) cnt += x - l[i];
    }
    return cnt <= k;
}

int main() {
    cin >> n >> k;
    vector<ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];
    for (int i = 0; i < n; ++i)
        a[i] > s / n ? h.push_back(a[i]) : l.push_back(a[i]);
    ll l1 = s / n - 1, r1 = 1e9 + 1, l2 = 0, r2 = s / n + 1;
    while (l1 + 1 < r1) {
        ll mid = (l1 + r1) / 2;
        if (f1(mid)) r1 = mid;
        else l1 = mid;
    }
    while (l2 + 1 < r2) {
        ll mid = (l2 + r2) / 2;
        if (f2(mid)) l2 = mid;
        else r2 = mid;
    }
    cout << max(r1 - l2, (ll) ((s % n) != 0));
}
