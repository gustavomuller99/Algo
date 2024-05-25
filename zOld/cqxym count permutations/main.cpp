#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
int main() {
    int t; cin>>t; while(t--) {
        ll x,ans=1; cin>>x;
        for (int i = 3; i <= 2*x; ++i) ans *= i, ans %= mod;
        cout << ans << "\n";
    }
}
