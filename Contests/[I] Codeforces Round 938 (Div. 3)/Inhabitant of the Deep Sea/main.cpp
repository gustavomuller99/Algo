#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll f = (k + 1) / 2, b = k / 2;
        deque<ll> d;
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            d.push_back(x);
        }
        int ans = 0;
        while (b > 0 && !d.empty()) {
            ll dur = d.back();
            d.pop_back();
            ans++;
            if (b < dur) d.push_back(dur - b), ans--;
            b -= min(b, dur);
        }
        while (f > 0 && !d.empty()) {
            ll dur = d.front();
            d.pop_front();
            ans++;
            if (f < dur) d.push_front(dur - f), ans--;
            f -= min(f, dur);
        }
        cout << ans << "\n";
    }
}
