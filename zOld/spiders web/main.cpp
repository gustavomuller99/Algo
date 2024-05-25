#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    int ans = 0;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int k; cin>>k; a[i].resize(k);
        for (int j = 0; j < k; ++j) cin>>a[i][j];
        sort(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < n; ++i) {
        int f = (i+1) % n, p = i == 0 ? n-1 : i-1;
        int lp = 0, rp = 0, lf = 0, rf = 0;
        for (int j = 1; j < a[i].size(); ++j) {
            while(rf < a[f].size()-1 && a[f][rf+1] <= a[i][j]) rf++;
            while(rp < a[p].size()-1 && a[p][rp+1] <= a[i][j]) rp++;
            while(lf < a[f].size()-1 && a[f][lf] < a[i][j-1]) lf++;
            while(lp < a[p].size()-1 && a[p][lp] < a[i][j-1]) lp++;
            int af, ap;
            if(a[f][rf] < a[i][j-1] || a[f][lf] > a[i][j]) af = 0; else af = rf - lf + 1;
            if(a[p][rp] < a[i][j-1] || a[p][lp] > a[i][j]) ap = 0; else ap = rp - lp + 1;
            if(af != ap) ans++;
        }
    }
    cout << ans;
}
