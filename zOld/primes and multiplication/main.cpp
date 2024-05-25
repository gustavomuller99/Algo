#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll mod = 1e9+7;

ll binpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll x,n; cin>>x>>n;
    set<ll> d;
    for (ll i = 2; i*i <= x; ++i) {
        if(x % i == 0) {
            d.insert(i);
            while(x % i == 0) x/=i;
        }
    }
    if(x != 1) d.insert(x);
    ll ans = 1;
    for(ll k : d) {
        ll y = n;
        while(y >= k)
        {
            ans=ans * binpow(k, y / k) % mod;
            y /= k;

        }
    }
    cout << ans << "\n";
}
