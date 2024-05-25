#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, k; cin>>n>>k;
        vector<int> p(1e3+1, INT_MAX), m(n), c(n), d(min(k + 1, 12 * n + 1));
        p[1] = 0;
        for (int i = 1; i < p.size(); ++i)
            for (int j = 1; j <= i; ++j)
                if(i + i/j < p.size()) p[i + i/j] = min(p[i + i/j], p[i] + 1);
        for (int i = 0; i < n; ++i) {
            int x; cin>>x;
            m[i] = p[x];
        }
        for (int i = 0; i < n; ++i) cin>>c[i];
        for (int i = 0; i < n; ++i) {
            for (int j = d.size() - 1; j >= m[i]; --j) {
                d[j] = max(d[j], d[j-m[i]] > 0 ? d[j-m[i]] + c[i] : 0);
            }
            if(m[i] < d.size()) d[m[i]] = max(d[m[i]], c[i]);
        }
        int ans = 0;
        for (int i = 0; i < d.size(); ++i) ans = max(ans, d[i]);
        cout << ans << "\n";
    }
}
