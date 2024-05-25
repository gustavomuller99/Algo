#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n; ll p; cin>>n>>p;
    vector<ll> a(n); ll s = 0;
    for (int i = 0; i < n; ++i) cin>>a[i], s += a[i];
    int l = -1, r = -1, b = 0;
    ll am = ULLONG_MAX, c = (p / s) * s, cm = (p / s) * n;
    while(l < n) {
        while(c < p) {
            r++;
            c += a[r%n]; cm++;
        }
        if(c >= p && cm < am && l >= 0) am = cm, b = l;
        if(l >= 0)
            c -= a[l],
            cm--;
        l++;
    }
    cout << b+1 << " " << am << "\n";
}
