#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0; cin>>n;
    vector<int> a(n), f(n+1, -1), l(n+1, -1);
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        if(f[a[i]] == -1) f[a[i]] = i;
        l[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if(f[a[i]] == l[a[i]]) continue;
        p.emplace_back(f[a[i]], l[a[i]]);
        f[a[i]] = l[a[i]] = 1;
    }
    if(!p.empty()) {
        sort(p.begin(), p.end());
        int m = p[0].second;
        ans += p[0].second - p[0].first - 1;
        for (int i = 0; i < p.size();) {
            int mm = m, ii = i;
            while(i < p.size() - 1 && p[i+1].first < mm)
                m = max(m, p[i+1].second), i++;
            if(m != mm) ans += m - mm - 1;
            if(i == ii) {
                while(i < p.size() && p[i].first < m) i++;
                if(i < p.size()) ans += p[i].second - p[i].first - 1, m = p[i].second;
            }
        }
    }
    cout << ans;
}
