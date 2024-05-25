#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            ll k; cin >> k; s += k;
        }
        if (s % 2 == 0 && (x % 2 == y % 2) || s % 2 && (x % 2 != y % 2)) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
