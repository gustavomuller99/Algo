#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, ans; string s; cin>>n>>s;
        ans = n-1;
        for (int i = 0; i < n; ++i) ans += s[i]-'0', ans -= (s[i]=='0' && i != n-1);
        cout << ans << "\n";
    }
}
