#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, c; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        c = a[0];
        for (int i = 1; i < n; ++i) {
            if(a[i] < a[i-1]) c -= (a[i-1] - a[i]);
        }
        cout << (c >= 0 ? "YES\n" : "NO\n");
    }
}
