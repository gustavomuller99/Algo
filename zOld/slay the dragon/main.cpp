#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin>>n;
    ll s = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i], s += a[i];
    sort(a.begin(), a.end());
    cin>>m;
    for (int i = 0; i < m; ++i) {
        ll x,y,l=-1,r=n-1; cin>>x>>y;
        while(l + 1 < r) {
            ll mid = (l+r)/2;
            if(a[mid] < x) l = mid;
            else r = mid;
        }
        cout << min(
                (y > (s - a[r]) ? y - (s - a[r]) : 0) + (x > a[r] ? x - a[r] : 0),
                r > 0 ? (y > (s - a[r-1]) ? y - (s - a[r-1]) : 0) + (x > a[r-1] ? x - a[r-1] : 0) : LLONG_MAX) << "\n";
    }
}
