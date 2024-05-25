#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
ll f(ll x) {
    ll s = 0;
    for (int i = 1; i <= n; ++i)
        s += min(n, x/i - (x%i == 0));
    return s;
}
int main() {
    cin>>n>>k;
    ll l = 0, r = 1e10+1;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        if(f(mid) < k) l = mid;
        else r = mid;
    }
    cout << l;
}
