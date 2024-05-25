#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll n = 0, m = 0;
        for (int i = 0; i < 2 * s.size() - 1; ++i) {
            n = (s[i % s.size()] == '1' ? n + 1 : 0);
            m = max(n, m);
        }
        if (m == 1) cout << "1\n";
        else if (m == 2 * s.size() - 1) cout << (ll) s.size() * (ll) s.size() << "\n";
        else cout << (m / 2 + (m % 2 == 1)) * (m / 2 + 1) << "\n";
    }
}
