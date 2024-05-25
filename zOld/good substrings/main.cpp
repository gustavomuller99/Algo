#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, ans = 0, b;
    string s, t;
    cin>>s>>t>>k;
    vector<bool> g(26);
    set<string> st;
    for (int i = 0; i < 26; ++i) g[i] = t[i] == '1';
    for (int i = 0; i < s.size(); ++i) {
        string a; b = 0;
        for (int j = i; j < s.size(); ++j) {
            if(!g[s[j]-'a']) b++;
            if(b > k) break;
            a += s[j];
            if(!st.count(a)) ans++;
            st.insert(a);
        }
    }
    cout << ans;
}
