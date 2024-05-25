#include <bits/stdc++.h>

using namespace std;
const int M = 10001;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        bitset<M> d;
        int cst = 0, s = 0, ans = INT_MAX;
        for (int i = 0; i < n; ++i) cin >> a[i], cst += (n - 2) * a[i] * a[i], s += a[i];
        for (int i = 0; i < n; ++i) cin >> b[i], cst += (n - 2) * b[i] * b[i], s += b[i];
        d[a[0]] = 1;
        d[b[0]] = 1;
        for (int i = 1; i < n; ++i) {
            bitset<M> p;
            for (int j = M - 1; j >= 0; --j) {
                if (j - a[i] >= 0)
                    p[j] = d[j - a[i]] | p[j];
                if (j - b[i] >= 0)
                    p[j] = d[j - b[i]] | p[j];
            }
            d = p;
        }
        for (int i = 0; i < M; ++i) {
            if (d[i]) ans = min(ans, i * i + (s - i) * (s - i));
        }
        cout << ans + cst << "\n";
    }
}
