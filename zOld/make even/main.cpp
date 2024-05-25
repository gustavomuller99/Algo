#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main() {
    int t; cin>>t; while(t--) {
        string s; cin>>s;
        int ans = -1;
        if((s[s.size()-1]-'0') % 2 == 0) ans = 0;
        else if((s[0]-'0') % 2 == 0) ans = 1;
        else {
            for (int i = 1; i < s.size()-1; ++i) if((s[i]-'0') % 2 == 0) ans = 2;
        }
        cout << ans << "\n";
    }
}
