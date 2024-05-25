#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
stack<pair<ll, ll>> f, b;
void add(ll x) {
    f.push({x, f.empty() ? x : gcd(x, f.top().second)});
}
void remove() {
    if(b.empty()) {
        b.push({f.top().first, f.top().first}); f.pop();
        while(!f.empty()) b.push({f.top().first, gcd(f.top().first, b.top().second)}), f.pop();
    } else b.pop();
}

int main() {
    int n; cin>>n;
    int ans = INT_MAX;
    while(n--) {
        ll x; cin>>x; add(x);
        while(gcd(b.empty() ? 0 : b.top().second, f.empty() ? 0 : f.top().second) == 1)
            ans = min(ans, (int) (f.size() + b.size())),
            remove();
    }
    cout << (ans == INT_MAX ? -1 : ans);
}
