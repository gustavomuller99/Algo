#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a, b;
ll n, k;
bool f(ll x) {
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        ll t = x - b[i], l = -1, r = n+1;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(a[mid] < t) l = mid;
            else r = mid;
        }
        s += (l+1);
    }
    return s < k;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>k;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) cin>>b[i];
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    ll l = INT_MIN, r = INT_MAX;
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}
