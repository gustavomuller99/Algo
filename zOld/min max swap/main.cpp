#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(n), b(n);
        int ma = 0, mb = 0;
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n; ++i) cin>>b[i];
        for (int i = 0; i < n; ++i) ma = max(ma, min(a[i], b[i]));
        for (int i = 0; i < n; ++i) mb = max(mb, max(a[i], b[i]));
        cout << ma * mb << "\n";
    }
}
