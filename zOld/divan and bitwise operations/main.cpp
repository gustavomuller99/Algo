#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll mod = 1e9+7;
int main() {
    int t; cin>>t; while(t--) {
        int n, m; cin>>n>>m;
        ll p = 1, k = 0;
        for (int i = 0; i < n-1; ++i) p *= 2, p %= mod;
        for (int i = 0; i < m; ++i) {
            ll x; cin>>x>>x>>x;
            k |= x;
        }
        cout << (p * k) % mod << "\n";
    }
}
