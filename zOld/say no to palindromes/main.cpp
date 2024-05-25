#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,m,k=0; string s, t = "abc";
    cin>>n>>m>>s;
    vector<vector<int>> d(6, vector<int> (n));
    do {
        for (int i = 0; i < n; ++i) {
            d[k][i] = (i > 0 ? d[k][i-1] : 0) + (s[i] != t[i%3]);
        }
        k++;
    } while(next_permutation(t.begin(), t.end()));
    while(m--) {
        int l, r, ans = INT_MAX; cin>>l>>r; r--, l--;
        for (int i = 0; i < 6; ++i) {
            ans = min(ans, d[i][r] - (l > 0 ? d[i][l-1] : 0));
        }
        cout << ans << "\n";
    }
}
