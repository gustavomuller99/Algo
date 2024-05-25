#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, cnt = 0; cin>>n>>m;
    string s, t; cin>>s>>t;
    vector<int> a(27), cur(27);
    for(char c: t) a[c-'a']++;
    int r = -1, l = 0;
    long long ans = 0;
    while(r < n) {
        while(l < r && cnt) {
            cur[s[l]-'a']--;
            if(cur[s[l]-'a'] == a[s[l]-'a']) cnt--;
            l++;
        }
        if(cnt == 0 && r >= 0) ans += (r-l+1);
        r++;
        if(cur[s[r]-'a'] == a[s[r]-'a']) cnt++;
        cur[s[r]-'a']++;
    }
    cout << ans;
}
