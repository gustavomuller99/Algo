#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        int n; ll s;
        cin>>n>>s;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        int l = 0, r = 0, lo = -1, hi = -1;
        while(r < n) {
            s += a[r];
            while(s < 0) s -= a[l], l++;
            if(l <= r && r - l >= hi - lo) lo = l, hi = r;
            r++;
        }
        if(lo == -1) cout << "-1\n";
        else cout << lo + 1 << " " << hi + 1 << "\n";
    }
}
