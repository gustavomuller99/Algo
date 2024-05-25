#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define ll unsigned long long
string a,b; ll k;
bool e(int p) {
    for (int i = 0; i < a.size(); ++i) if(a[i] != b[(i+p)%a.size()]) return false;
    return true;
}
int main() {
    cin>>a>>b>>k;
    vector<int> pos;
    for (int i = 0; i < a.size(); ++i) if(e(i)) pos.push_back(i);
    ll l = 1, z = 0, ans = 0;
    if(!k) { cout << (a == b ? 1 : 0); return 0; }
    while(--k) {
        ll p = l;
        l *= (a.size()-2), l += z; l %= mod;
        z = (a.size()-1) * p; z %= mod;
    }
    for(int x: pos) {
        if(!x) ans += z, ans %= mod;
        else ans += l, ans %= mod;
    }
    cout << ans;
}
