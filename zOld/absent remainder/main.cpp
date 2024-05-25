#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, m = INT_MAX; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i]; m = min(m, a[i]);
        }
        int cnt = 0, i = 0;
        while(cnt < n/2) {
            if (a[i] != m) cout << a[i] << " " << m << "\n", cnt++;
            i++;
        }
    }
}
