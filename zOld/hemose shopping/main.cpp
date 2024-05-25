#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, x, ans = 1; cin>>n>>x;
        vector<int> a(n),b(n);
        for (int i = 0; i < n; ++i) cin>>a[i], b[i] = a[i];
        sort(a.begin(),a.end());
        for (int i = n-x; i < x; ++i) {
            if(b[i] != a[i]) ans = 0;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
