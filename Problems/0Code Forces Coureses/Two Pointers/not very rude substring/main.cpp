#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main() {
    int n; ll c, cnt1 = 0, cnt2 = 0, cur = 0;
    cin>>n>>c;
    string s; cin>>s;
    int r = -1, l = 0, ans = 0;
    while(r < n) {
        while(l < r && cur > c) {
            if(s[l] == 'a') cnt1--, cur -= cnt2;
            if(s[l] == 'b') cnt2--;
            l++;
        }
        if(cur <= c) ans = max(ans, r-l+1);
        r++;
        if(s[r] == 'a') cnt1++;
        if(s[r] == 'b') cnt2++, cur += cnt1;
    }
    cout << ans;
}
