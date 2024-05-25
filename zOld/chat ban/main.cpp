#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll k, x;
ll f(ll m) {
    ll s = 0;
    s += min(k, m) * (min(k, m) + 1) / 2;
    if(m > k) s += (k - 1) * (k) / 2 - (2*k - 1 - m) * (2*k - m) / 2;
    return s;
}
int main() {
    int t; cin>>t; while(t--) {
        cin>>k>>x;
        ll l = -1, r = 2*k-1;
        while(l + 1 < r) {
            ll mid = l + (r - l) / 2;
            if(f(mid) < x) l = mid;
            else r = mid;
        }
        cout << r << "\n";
    }
}
