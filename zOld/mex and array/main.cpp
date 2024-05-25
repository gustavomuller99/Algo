#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, ans = 0; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            ans += (n - i) * (i + 1) * (1 + (a[i] == 0));
        }
        cout << ans << "\n";
    }
}
