#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k, pb, ps, mb = 0, ms = 0, sb = 0, ss = 0;
        cin >> n >> k >> pb >> ps;
        pb--, ps--;
        vector<ll> a(n), p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i]--;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < min(k, n + 1); ++i) {
            mb = max(mb, sb + (k - i) * a[pb]);
            sb += a[pb];
            pb = p[pb];

            ms = max(ms, ss + (k - i) * a[ps]);
            ss += a[ps];
            ps = p[ps];
        }
        if (mb > ms) cout << "Bodya\n";
        else if (ms > mb) cout << "Sasha\n";
        else cout << "Draw\n";
    }
}
