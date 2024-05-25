#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, ans=1; cin>>n;
        vector<int> a(n);
        vector<vector<int>> d(n, vector<int> (201));
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            if(i) for (int j = 1; j <= 200; ++j) d[i][j] = d[i-1][j];
            d[i][a[i]]++;
        }
        for (int i = 1; i <= 200; ++i) {
            int l = 0, r = n-1, cnt = 0;
            while(l < r) {
                while(l < r && a[l] != i) l++;
                while(l < r && a[r] != i) r--;
                cnt += 2;
                if(l < r) for (int j = 1; j <= 200; ++j) {
                    ans = max(ans, cnt + d[r-1][j] - d[l][j]);
                }
                l++, r--;
            }
        }
        cout << ans << "\n";
    }
}
