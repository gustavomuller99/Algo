#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t; while(t--) {
        ll n, m, k = 0, ans = 0;
        cin >> n >> m;
        bool f = false;
        while ((max(n, m) >> k) > 0) k++;
        while (--k >= 0) {
            int bm = (m >> k) % 2, bn = (n >> k) % 2;
            if (bm) {
                if (!f || !(bm xor bn)) ans += (1 << k);
            } else {
                if (bm xor bn) ans += (1 << k), f = true;
            }
        }
        if(!f) {
            k = 0;
            while((ans >> k) % 2) {
                if((ans >> k) % 2 xor (n >> k) % 2) ans &= ~(1 << k);
                k++;
            }
            ans |= (1 << k);
        }
        cout << (ans xor n) << "\n";
    }
}
