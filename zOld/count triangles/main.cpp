#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll a,b,c,d;
    ll ans=0; cin>>a>>b>>c>>d;
    vector<ll> s(b+c+1);
    for (ll i = a; i <= b; ++i) {
        if(i+b < s.size()) s[i+b]++;
        if(i+c+1 < s.size()) s[i+c+1]--;
    }
    for (int i = 1; i < s.size(); ++i) s[i] += s[i-1];
    for (ll i = c; i < s.size(); ++i) {
        ans += min(d - c + 1, i - c) * s[i];
    }
    cout << ans;
}
