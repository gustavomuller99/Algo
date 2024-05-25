#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, k = 0, p = -1, c; cin>>n;
        vector<int> a(n), ans(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            if(a[i] != a[i-1]) ++k;
            else p = i;
            ans[i] = k % 2 + 1;
        }
        if(k == 0) c = 1, ans[n-1] = 1;
        else {
            if(ans[n-1] == ans[0] &&
                a[n-1] != a[0] &&
                p == -1) c = 3, ans[n-1] = 3;
            else {
                c = 2;
                if(ans[n-1] == ans[0] &&
                    a[n-1] != a[0]) {
                    k = ans[p];
                    for (int i = p; i < n; ++i) {
                        if(a[i] != a[i-1]) ++k;
                        ans[i] = k % 2 + 1;
                    }
                }
            }
        }
        cout << c << "\n";
        for(int x : ans) cout << x << " "; cout << "\n";
    }
}