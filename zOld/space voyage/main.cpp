#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<pair<ll, ll>> a;
ll f(ll x) {
    ll s = 0;
    for (auto & i : a) {
        s += (i.first * x) / i.second;
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n, c; cin>>n>>c; c-=n;
    a.resize(n);
    bool z = true;
    for (int i = 0; i < n; ++i) cin>>a[i].first>>a[i].second, z &= a[i].first == 0;
    if(z && c == 0) { cout << "-1"; return 0; }
    if(z) { cout << "0"; return 0; }
    ll lo, hi, l = 0, r = ULLONG_MAX;
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if(f(mid) >= c) r = mid;
        else l = mid;
    } lo = r;
    l = 0, r = ULLONG_MAX;
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if(f(mid) > c) r = mid;
        else l = mid;
    } hi = l;
    cout << hi - lo + 1 << "\n";
}
