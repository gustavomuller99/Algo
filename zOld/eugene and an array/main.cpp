#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n; cin>>n;
    vector<ll> a(n+2);
    map<ll, ll> m;
    ll s = 0, hi = 0, ans = 0;
    m[0] = 1;
    for (int i = 2; i <= n+1; ++i) cin>>a[i];
    for (int i = 2; i <= n+1; ++i) {
        s += a[i];
        if(a[i]==0) hi = i-1;
        else hi = max(hi, m[s]);
        ans += max(0ll, i - (hi+1) - (a[i] == 0));
        m[s] = i;
    }
    cout << ans;
}
