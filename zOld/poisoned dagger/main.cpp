#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<ll> a;
ll h;
bool f(ll x) {
    ll d = 0;
    for (int i = 0; i < a.size()-1; ++i) d += min(x, a[i+1] - a[i]);
    return d + x >= h;
}
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n>>h;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        ll l = 0, r = ULLONG_MAX;
        while(l + 1 < r) {
            ll mid = l + (r - l) / 2;
            if(f(mid)) r = mid;
            else l = mid;
        }
        cout << r << "\n";
    }
}
