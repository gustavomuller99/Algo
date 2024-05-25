#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int q; cin>>q; while(q--) {
        int n; cin>>n;
        vector<pair<ll, ll>> a(n);
        vector<vector<ll>> d(n, vector<ll> (3, ULLONG_MAX));
        for (int i = 0; i < n; ++i) cin>>a[i].first>>a[i].second;
        d[0][0] = 0, d[0][1] = a[0].second, d[0][2] = a[0].second * 2;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if(a[i-1].first + j != a[i].first + k) {
                        d[i][k] = min(d[i][k], d[i-1][j] + a[i].second * k);
                    }
                }
            }
        }
        cout << min(d[n-1][0], min(d[n-1][1], d[n-1][2])) << "\n";
    }
}


