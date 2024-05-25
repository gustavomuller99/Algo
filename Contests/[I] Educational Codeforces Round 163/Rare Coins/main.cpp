#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

vector<ll> a, b;
ll mod = 998244353;

int main() {
    ll n, q;
    cin >> n >> q;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) a[i] += a[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (i) b[i] += b[i - 1];
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        ll g = a[n - 1] - 2 * (a[r] - (l ? a[l - 1] : 0));
    }
}
