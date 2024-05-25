#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t; while(t--) {
        int n,ans=INT_MAX; cin>>n;
        vector<pair<int, int>> a(n),b(n);
        for (int i = 0; i < n; ++i) { int x; cin>>x; a[i] = {x, i}; }
        for (int i = 0; i < n; ++i) { int x; cin>>x; b[i] = {x, i}; }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = n-2; i >= 0; --i) b[i].second = min(b[i].second, b[i+1].second);
        for (int i = 0; i < n; ++i) ans = min(ans, a[i].second + b[i].second);
        cout << ans << "\n";
    }
}
