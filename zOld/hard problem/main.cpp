#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    vector<ll> c(n);
    vector<vector<ll>> ans(2, vector<ll> (n));
    for (int i = 0; i < n; ++i) cin >> c[i];
    string p, curr; cin >> p;
    ans[0][0] = 0, ans[1][0] = c[0];
    for (int i = 1; i < n; ++i) {
        cin >> curr;
        ans[0][i] = ans[1][i] = LLONG_MAX;
        string p_r = string(p.rbegin(), p.rend()), curr_r = string(curr.rbegin(), curr.rend());
        if(ans[0][i-1] != LLONG_MAX) {
            if(curr >= p) ans[0][i] = ans[0][i-1];
            if(curr_r >= p) ans[1][i] = ans[0][i-1] + c[i];
        }
        if(ans[1][i-1] != LLONG_MAX) {
            if(curr >= p_r) ans[0][i] = min(ans[0][i], ans[1][i-1]);
            if(curr_r >= p_r) ans[1][i] = min(ans[1][i], ans[1][i-1] + c[i]);
        }
        p = curr;
    }
    if(ans[0][n-1] != LLONG_MAX || ans[1][n-1] != LLONG_MAX) cout << min(ans[0][n-1], ans[1][n-1]);
    else cout << -1;
}
