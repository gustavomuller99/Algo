#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n; ll k; cin>>n>>k;
    string s; cin>>s;
    ll d[n+1][n+1];
    memset(d, 0, sizeof(d));
    vector<int> last(256, -1);
    d[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            d[i][j] += d[i-1][j];
            if(j) {
                d[i][j] += d[i-1][j-1];
                if(last[s[i-1]] != -1) d[i][j] -= d[last[s[i-1]]-1][j-1];
            }
        }
        last[s[i-1]] = i;
    }
    ll cost = 0, sum = 0;
    for (int i = n; i >= 0 && sum <= k; --i) {
        cost += min(d[n][i], k - sum) * (n - i);
        sum += min(d[n][i], k - sum);
    }
    if(sum >= k) cout << cost;
    else cout << -1;
}
