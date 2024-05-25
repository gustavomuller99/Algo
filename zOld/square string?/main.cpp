#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        bool ans = true;
        string s; cin>>s;
        int a = s.size() / 2 + s.size() % 2;
        for (int i = 0; i < a; ++i) {
            if(i + a >= s.size() || s[i] != s[i + a]) ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
