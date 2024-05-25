#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n,h,ans; cin>>n>>h;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        sort(a.begin(), a.end(), greater<>());
        ans = (h / (a[0] + a[1])) * 2 + (h % (a[0] + a[1]) ? (h % (a[0] + a[1]) > a[0] ? 2 : 1) : 0);
        cout << ans << "\n";
    }
}
