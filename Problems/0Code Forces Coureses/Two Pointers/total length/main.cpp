#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n; ll s; cin>>n>>s;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    ll ans = 0, cs = 0, l = 0, r = 0;
    while(r < n) {
        cs += a[r];
        while(cs > s && l < r) {
            cs -= a[l], l++;
        }
        if(cs <= s) ans += (r-l+1)*(r-l+2)/2;
        r++;
    }
    cout << ans;
}
