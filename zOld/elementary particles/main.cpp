#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while (t--) {
        int n, ans = -1; cin>>n;
        vector<int> a(150001);
        for (int i = 0; i < n; ++i) {
            int x; cin>>x;
            if(a[x] != 0) ans = max(ans, a[x] + n - i - 1);
            a[x] = i + 1;
        }
        cout << ans << "\n";
    }
}
