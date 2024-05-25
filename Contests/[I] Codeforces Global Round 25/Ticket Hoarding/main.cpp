#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<pair<ll, ll>> a(n), p;
        for (ll i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        ll tot = 0, qtd = (k + m - 1) / m;
        for (ll i = 0; i < qtd; ++i) {
            p.emplace_back(a[i].second, a[i].first);
            tot += m * a[i].first + (qtd * m - (i + 1) * m) * m;
        }
        sort(p.begin(), p.end());
        ll ans = tot;
        if (k % m) for (ll i = 0; i < p.size(); ++i) {
            ans = min(ans,
                      tot
                      - m * p[i].second
                      - (qtd * m - (i + 1) * m) * m
                      - (i * m) * m
                      + (k % m) * p[i].second
                      + (k - i * m - k % m) * (k % m)
                      + (i * m) * (k % m));
        }
        cout << ans << "\n";
    }
}
