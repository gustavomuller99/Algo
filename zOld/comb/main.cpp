#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin>>n>>m;
    vector<vector<ll>> a(n, vector<ll> (m)), d(n, vector<ll> (m, LLONG_MIN));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin>>a[i][j], a[i][j] += (j ? a[i][j-1] : 0);

    for (int i = 0; i < n; ++i) {
        if(i%2) for (int j = 0; j < m; ++j) {
            if(j > 0) a[i][j] = max(a[i][j], a[i][j-1]);
            if(j < m-1) d[i][j] = max(j ? d[i][j-1] : INT_MIN, a[i][j] + d[i-1][j+1]);
        }
        else for (int j = m-1; j >= 0; --j) {
            if(j < m-1) a[i][j] = max(a[i][j], a[i][j+1]);
            if(j > 0) d[i][j] = max(j < m-1 ? d[i][j+1] : INT_MIN , a[i][j] + (i ? d[i-1][j-1] : 0));
        }
    }

    ll ans = LLONG_MIN;
    for (int i = 0; i < m; ++i) ans = max(ans, d[n-1][i]);
    cout << ans;
}
