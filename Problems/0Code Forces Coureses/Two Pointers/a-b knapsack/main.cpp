#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, m; ll s,a,b;
    cin>>n>>m>>s>>a>>b;
    vector<ll> ca(n), cb(m);
    for (int i = 0; i < n; ++i) cin>>ca[i];
    for (int i = 0; i < m; ++i) cin>>cb[i];
    sort(ca.begin(), ca.end(), greater<>());
    sort(cb.begin(), cb.end(), greater<>());
    for (int i = 1; i < n; ++i) ca[i] += ca[i-1];
    for (int i = 1; i < m; ++i) cb[i] += cb[i-1];
    int r = -1;
    ll ans = 0;
    while(r < n) {
        ll c = s - (r+1)*a;
        int ib = -1;
        if(c > 0) ib = min((c / b) - 1, (ll) (cb.size() - 1));
        c -= (ib+1)*b;
        if(c >= 0) ans = max(ans, (r >= 0 ? ca[r] : 0) + (ib >= 0 ? cb[ib] : 0));
        r++;
    }
    cout << ans;
}
