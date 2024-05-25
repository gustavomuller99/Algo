#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), p(m), f(k);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> p[i];
        for (int i = 0; i < k; ++i) cin >> f[i];
        std::sort(p.begin(), p.end());
        std::sort(f.begin(), f.end(), greater<>());
        vector<int> g(2);
        int idx;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] > g[0]) idx = i, g[1] = g[0], g[0] = a[i] - a[i - 1];
            else if (a[i] - a[i - 1] > g[1]) g[1] = a[i] - a[i - 1];
        }
        int r = 0, minv = INT_MAX;
        for (int i = 0; i < m; ++i) {
            while(r < k - 1 &&
                max(a[idx] - (p[i] + f[r]), (p[i] + f[r]) - a[idx - 1]) >=
                max(a[idx] - (p[i] + f[r + 1]), (p[i] + f[r + 1]) - a[idx - 1])) r++;
            minv = min(minv, max(g[1], max(a[idx] - (p[i] + f[r]), (p[i] + f[r]) - a[idx - 1])));
        }
        cout << min(minv, g[0]) << "\n";
    }
}
