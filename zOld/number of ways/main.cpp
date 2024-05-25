#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    ll s = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i]; s+=a[i];
    }
    if(s%3) cout << 0;
    else {
        ll t = 0, am = 0, ans = 0;
        for (int i = 0; i < n-1; ++i) {
            t+=a[i];
            if(t == 2*(s/3)) ans += am;
            if(t == s/3) am++;
        }
        cout << ans;
    }
}
