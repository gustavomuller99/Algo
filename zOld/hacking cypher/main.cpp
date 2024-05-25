#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin>>s;
    vector<int> ra(s.size()), rb(s.size());
    int a,b; cin>>a>>b;
    int r = 0, ans = -1;
    for (int i = 0; i < s.size(); ++i) {
        r = (r*10 + (s[i]-'0')) % a;
        ra[i] = r;
        cout << ra[i] << " ";
    } cout << "\n";
    r = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        r = (r*10 + (s[i]-'0')) % b;
        rb[i] = r;
        cout << rb[i] << " ";
    } cout << "\n";
    for (int i = 0; i < s.size() - 1; ++i) {
        if(ra[i] == 0 && rb[i] == 0) ans = i;
    }
    if(ans == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        string aa = s.substr(0, ans), ab = s.substr(ans, s.size());
        cout << aa << "\n" << ab;
    }
}
