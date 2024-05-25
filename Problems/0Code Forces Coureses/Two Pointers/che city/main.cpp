#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n; ll x; cin>>n>>x;
    vector<ll> d(n);
    for (int i = 0; i < n; ++i) cin>>d[i];
    ll ans = 0, l = 0, r = 1;
    while(r < n) {
        while(d[r] - d[l] > x) l++;
        ans += l;
        r++;
    }
    cout << ans;
}
