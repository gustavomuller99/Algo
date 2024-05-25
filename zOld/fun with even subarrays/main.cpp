#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        int l = 1, ans = 0;
        for (int i = n-2; i >= 0; --i) {
            if(a[i] != a[n-1] && i < n-l) l*=2, ans++;
            if(a[i] == a[n-1] && i < n-l) l++;
        }
        cout << ans << "\n";
    }
}
