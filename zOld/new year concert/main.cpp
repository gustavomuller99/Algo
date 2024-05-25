#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll P = 1000000007;

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }

stack<pair<ll, ll>> f, b;

void add(ll x) {
    f.push({x, f.empty() ? x : gcd(x, f.top().second)});
}
void remove() {
    if(b.empty()) {
        b.push({f.top().first, f.top().first}); f.pop();
        while(!f.empty()) b.push({f.top().first, gcd(f.top().first, b.top().second)}), f.pop();
        b.pop();
    } else b.pop();
}

ll get(ll x) {
    return gcd(x, gcd(b.empty() ? 0 : b.top().second, f.empty() ? 0 : f.top().second));
}

int main() {
    int n; cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    int r = 0, l = 0, ans = 0;
    while(r < n) {
        while(l < r && get(a[r]) < r - l + 1) remove(), l++;
        if(get(a[r]) == r - l + 1) add(P), ans++;
        else add(a[r]);
        cout << ans << " ";
        r++;
    }
}
