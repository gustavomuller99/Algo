#include <bits/stdc++.h>
    using namespace std;
     
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        string s, a, p, r; cin>>s;
        reverse(s.begin(), s.end());
        vector<int> f(26);
        for(char c : s) {
            if(!f[c-'a']) a += c;
            f[c-'a']++;
        }
        reverse(a.begin(), a.end());
        int n = 0;
        for (int i = 0; i < a.size(); ++i) {
            n += f[a[i]-'a'] / (i+1);
        }
        reverse(s.begin(), s.end());
        p = s.substr(0, n);
        for(char c : a) {
            r += p;
            p.erase(remove(p.begin(), p.end(), c), p.end());
        }
        if(r == s) cout << s.substr(0, n) << " " << a << "\n";
        else cout << "-1\n";
    }
}