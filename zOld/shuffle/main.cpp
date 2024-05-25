#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 998244353;
int main() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    int c0=0, c1=0, l=0, ans=0;
    int cb[n+1][n+1];
    memset(cb, 0, sizeof(cb));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, n); ++j) {
            if(j == 0 || j == i) cb[i][j] = 1;
            else cb[i][j] = (cb[i-1][j-1] + cb[i-1][j]) % mod;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += s[i] == '1';
    if(cnt >= k) for (int i = 0; i < s.size(); ++i) {
        (s[i] == '1' ? c1++ : c0++);
        while(l < i && c1 > k) {
            (s[l] == '1' ? c1-- : c0--);
            l++;
        }
        int cc0 = 0, cc1 = 0;
        for (int j = l; j < i; ++j) {
            int cb1 = c1 - cc1 - (s[j] == '0') - (s[i] == '0');
            int cb0 = c0 - cc0 - (s[j] == '1') - (s[i] == '1');
            if(cb1 >= 0 && cb0 >= 0) ans += cb[cb0 + cb1][cb0];
            ans %= mod;
            (s[j] == '1' ? cc1++ : cc0++);
        }
    }
    cout << (ans + 1) % mod;
}
