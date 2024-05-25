#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        ll n, c, ans = INT_MAX; cin>>n>>c;
        vector<ll> a(n), b(n-1), d(n), p(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n-1; ++i) cin>>b[i];
        for (int i = 0; i < n; ++i) {
            ll pr = (b[i] >= p[i] ? (b[i] - p[i]) / a[i] + (int) ((b[i] - p[i]) % a[i] != 0) : 0);
            if(i < n-1) {
                p[i+1] = a[i] * pr - b[i] + p[i];
                d[i+1] = pr + d[i] + 1;
            }
            d[i] += (c >= p[i] ? (c - p[i]) / a[i] + (int) ((c - p[i]) % a[i] != 0) : 0);
            ans = min(ans, d[i]);
        }
        cout << ans << "\n";
    }
}
