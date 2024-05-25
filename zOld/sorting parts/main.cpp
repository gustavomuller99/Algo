#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(n), m(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = n-1; i >= 0; --i) m[i] = min(a[i], i < n - 1 ? m[i+1] : INT_MAX);
        int k = 0; bool ans = true;
        for (int i = 0; i < n - 1; ++i) {
            k = max(k, a[i]);
            ans &= k <= m[i + 1];
        }
        cout << (ans ? "NO\n" : "YES\n");
    }
}
