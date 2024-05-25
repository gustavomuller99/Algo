#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n; ll s; cin>>n>>s;
    vector<ll> w(n), c(n);
    for (int i = 0; i < n; ++i) cin>>w[i];
    for (int i = 0; i < n; ++i) cin>>c[i];
    int r = -1, l = 0; ll cw = 0, cc = 0, ans = 0;
    while(r < n) {
        while(l < r && cw > s) cw -= w[l], cc -= c[l], l++;
        if(cw <= s) ans = max(ans, cc);
        r++;
        cw += w[r];
        cc += c[r];
    }
    cout << ans;
}
