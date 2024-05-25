#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll a,b; cin>>a>>b;
    if (b > a) swap(b, a);
    ll x = 0; int k = 0;
    bool c = false, ans = true;
    while (a >> k != 0 && k < 64) k++; k--;
    while(k >= 0)  {
        bool bb = (b >> k) % 2;
        bool ab = (a >> k) % 2;
        if(bb) {
            if(c == ab) ans = false;
            else c = !ab;
        } else {
            if(c) x += (1ULL << k);
            c = ab;
        }
        k--;
    }
    if(ans) cout << x << " " << (b xor x);
    else cout << "-1";
}
