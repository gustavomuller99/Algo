#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, k; cin>>n>>k;
        string s; cin>>s;
        bool p = false;
        for (int i = 0; i < n / 2; ++i) if(s[i] != s[n-i-1]) p = true;
        if(p && k > 0) cout << "2\n";
        else cout << "1\n";
    }
}
