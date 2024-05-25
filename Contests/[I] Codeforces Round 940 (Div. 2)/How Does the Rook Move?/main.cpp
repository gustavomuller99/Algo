#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
ll mod = 1000000007;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            if (x == y) n--;
            else n -= 2;
        }
        vector<ll> d(n + 1);
        d[0] = d[1] = 1;
        for (int i = 2; i <= n; ++i) {
            d[i] = d[i - 1];
            if (i > 1) d[i] = (d[i] + (i - 1) * 2 * d[i - 2]) % mod;
        }
        cout << d[n] % mod << "\n";
    }
}
