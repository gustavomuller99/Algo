#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll, ll>> a;
int n, k;

ll f(ll x) {
    ll s = 0;
    for (int i = 0; i < n; ++i) s += min(a[i].second - a[i].first + 1, max(0ll, x - a[i].first));
    return s;
}

int main() {
    cin>>n>>k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin>>a[i].first>>a[i].second;
    ll l = -1e10, r = 1e10;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(f(mid) <= k) l = mid;
        else r = mid;
    }
    cout << l;
}
