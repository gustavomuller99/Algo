#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t; while(t--) {
        ll n, k; cin>>n>>k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        ll ans = LLONG_MIN;
        int s = sqrt(max(1ll, n*n - n - 2*k*n));
        for (ll i = s-1; i < n-1; ++i) {
            for (ll j = i+1; j < n; ++j) {
                ans = max(ans, (i+1)*(j+1) - k*(a[i] | a[j]));
            }
        }
        cout << ans << "\n";
    }
}
