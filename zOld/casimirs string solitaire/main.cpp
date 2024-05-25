#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        string s; cin>>s;
        vector<int> a(3);
        for (int i = 0; i < s.size(); ++i) a[s[i]-'A']++;
        cout << (a[0] + a[2] == a[1] ? "YES\n" : "NO\n");
    }
}
