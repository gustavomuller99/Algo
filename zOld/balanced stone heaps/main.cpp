#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a;
bool f(ll x) {
    vector<ll> c(a.size());
    ll l, s;
    for (int i = a.size() - 1; i > 1; --i) {
        l = max(0ll, x - c[i]), s = (a[i] - l) - (a[i] - l) % 3;
        c[i - 1] += s/3;
        c[i - 2] += 2*s/3;
    }
    for (int i = 0; i < a.size(); ++i)
        if(a[i] + c[i] < x) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        ll l = 0, r = 1e9+1;
        while(l + 1 < r) {
            ll mid = l + (r - l) / 2;
            if(f(mid)) l = mid;
            else r = mid;
        }
        cout << l << "\n";
    }
}
