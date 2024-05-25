#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, m, ans=INT_MAX; cin>>n>>m;
        vector<vector<int>> a, h, v(n+1, vector<int> (m+1));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin>>a[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                h[i][j] = a[i][j] + a[i][j-1];
        for (int j = 1; j <= n; ++j)
            for (int i = 1; i <= m; ++i)
                v[i][j] = a[i][j] + a[i-1][j];

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(abs(i-j) >)
            }
        }
        cout << ans << "\n";
    }
}
