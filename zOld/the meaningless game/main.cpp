#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        ll a,b; cin>>a>>b;
        ll c=a*b;
        ll l = 1, r = 1e6+5;
        while(l + 1 < r) {
            ll mid = (l+r) / 2;
            if(mid*mid*mid > c) r = mid;
            else l = mid;
        }
        if(l*l*l == c && a%l==0 && b%l==0) cout << "YES\n";
        else cout << "NO\n";
    }
}
