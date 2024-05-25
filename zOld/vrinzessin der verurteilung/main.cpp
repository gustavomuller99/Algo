#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin>>t; while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        map<string, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s.substr(i, 1)] = true;
            m[s.substr(i, 2)] = true;
            m[s.substr(i, 3)] = true;
        }
        string ans, c;
        for (char i = 'a'; i <= 'z'; ++i) {
            c = ""; c += i;
            if(!m[c] && (ans.empty() || ans.size() > 1)) ans = c;
            for (char j = 'a'; j <= 'z'; ++j) {
                c = ""; c += i, c += j;
                if(!m[c] && (ans.empty() || ans.size() > 2)) ans = c;
            }
        }
        cout << ans << "\n";
    }
}
