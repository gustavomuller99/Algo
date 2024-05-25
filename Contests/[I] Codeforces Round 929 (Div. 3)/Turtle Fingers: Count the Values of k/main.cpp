#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

void solve() {
    ll a, ac, b, bc, l;
    cin >> a >> b >> l;
    ac = a, bc = b;
    vector<ll> ap, bp;
    ap.push_back(1), bp.push_back(1);
    while (a <= l) ap.push_back(a), a = a * ac;
    while (b <= l) bp.push_back(b), b = b * bc;
    set<ll> k;
    for (ll i : ap) {
        for (ll j : bp) {
            if (l % (i * j) == 0) {
                k.insert(l / (i * j));
            }
        }
    }
    cout << k.size() << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
