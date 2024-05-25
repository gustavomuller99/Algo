#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        string s; cin>>s;
        int cnt = 0;
        for (char i : s) cnt += i == 'N';
        if(cnt == 1) cout << "NO\n";
        else cout << "YES\n";
    }
}
