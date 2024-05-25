#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, k; cin>>n>>k;
    unsigned long long ans = 0;
    vector<ll> a(n);
    map<ll, ll> c, d;
    for (int i = 0; i < n; ++i) cin>>a[i], d[a[i]]++;
    for (int i = 0; i < n; ++i) {
        d[a[i]]--;
        if(a[i] % k == 0) ans += (c[a[i] / k] * d[a[i] * k]);
        c[a[i]]++;
    }
    cout << ans;
}
