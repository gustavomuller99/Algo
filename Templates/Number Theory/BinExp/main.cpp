#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

/* multiply all n^p where p is a power of 2 and
 * p is in the binary representation of x */
ll bin_exp(ll n, ll x) {
    ll res = 1;
    while(x > 0) {
        if(x % 2) res = res * n, res %= mod;
        n *= n; n %= mod;
        x >>= 1;
    }
    return res;
}

int main() {

}
