#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        bool ans = true;
        vector<int> p(n+1), pr(n+1), w(n+1), f(n+1), acc(n+1);
        for (int i = 1; i <= n; ++i) {
            cin>>f[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin>>p[i];
            pr[p[i]] = i;
        }
        for (int i = 1; i <= n; ++i) if(pr[i] < pr[f[i]]) ans = false;
        if(ans) {
            w[0] = 0;
            for (int i = 2; i <= n; ++i) {
                acc[p[i]] = acc[f[p[i]]];
                w[p[i]] = (i - 1) - acc[p[i]];
                acc[p[i]] += w[p[i]];
            }
            for (int i = 1; i <= n; ++i) cout << w[i] << " "; cout << "\n";
        } else cout << "-1\n";
    }
}
