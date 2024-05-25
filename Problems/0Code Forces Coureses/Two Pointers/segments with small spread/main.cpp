#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    multiset<ll> s;
    for (int i = 0; i < n; ++i) cin>>a[i];
    long long l = 0, r = 0, ans = 0; s.insert(a[0]);
    while(l < n) {
        while(r < n-1) {
            r++; s.insert(a[r]);
            if(*(--s.end()) - *s.begin() > k) {
                s.erase(s.find(a[r]));
                r--;
                break;
            }
        }
        ans += r - l + 1;
        s.erase(s.find(a[l]));
        l++;
    }
    cout << ans;

}
