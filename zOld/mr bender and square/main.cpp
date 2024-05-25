#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll n,x,y,c;
ll cnt(ll t, ll f, ll s) {
    return t * (t+1) / 2 -
            (t > f ? (t - f) * (t - f + 1) / 2 : 0) -
            (t > s ? (t - s) * (t - s + 1) / 2 : 0) +
            (t > f + s ? (t - (f + s)) * (t - (f + s) + 1) / 2 : 0);
}
ll f(ll t) {
    int b = n - x + 1, r = n - y + 1, u = x, l = y;
    ll s = cnt(t, b, r) + cnt(t, b, l) + cnt(t, u, r) + cnt(t, u, l);
    s -= min(t, x) + min(t, y) + min(t, n - x + 1) + min(t, n - y + 1);
    return s + 1;
}
int main() {
    cin>>n>>x>>y>>c;
    ll l = 0, r = LLONG_MAX;
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if(f(mid) >= c) r = mid;
        else l = mid;
    }
    cout << l;
}
