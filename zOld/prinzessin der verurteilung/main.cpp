#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        string s, ans, a, b, c; cin>>s;
        for (char i = 'a'; i <= 'z'; ++i) {
            a = i;
            for (char j = 'a'; j <= 'z'; ++j) {
                b = i, b += j;
                for (char k = 'a'; k <= 'z'; ++k) {
                    c = i, c += j, c += k;
                    for (int l = 0; l < s.size(); ++l) {
                        if(s.substr(l, 1) == a) a = "";
                        if(s.substr(l, 2) == b) b = "";
                        if(s.substr(l, 3) == c) c = "";
                    }
                    if(!c.empty() && ans.empty()) ans = c;
                }
                if(!b.empty() && ans.size() > 2) ans = b;
            }
            if(!a.empty() && ans.size() > 1) ans = a;
        }
        cout << ans << "\n";
    }
}