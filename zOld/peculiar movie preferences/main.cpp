#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        bool ans = false;
        map<string, bool> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n; ++i) {
            string s = a[i];
            bool p = true;
            for (int j = 0; j < s.size() / 2; ++j) if(s[j] != s[s.size() - j - 1]) p = false;
            for (int j = 0; j < s.size() - 1; ++j) {
                string f;
                for (int k = s.size() - 1; k >= j; k--) f += s[k];
                ans |= m[f];
            }
            ans |= p;
            m[s] = true;
        }
        m = map<string, bool> ();
        for (int i = n-1; i >= 0; --i) {
            string s = a[i];
            for (int j = 0; j < s.size() - 1; ++j) {
                string f;
                for (int k = s.size() - j - 1; k >= 0; k--) f += s[k];
                ans |= m[f];
            }
            m[s] = true;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}
