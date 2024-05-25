#include <bits/stdc++.h>
using namespace std;


string s, t;
bool sol(int p) {
    vector<int> a(t.size()); a[0] = 1;
    for (int i = 1; i < t.size(); ++i) {
        int l = p;
        while(p < s.size()) {
            p++;
            if(s[p] == t[i] && (p-l-1) % 2 == 0) {
                a[i] = 1; break;
            }
        }
    }
    return accumulate(a.begin(), a.end(), 0) == t.size() &&
            (s.size() == p || (s.size()-p-1) % 2 == 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while(q--) {
        cin>>s>>t;
        pair<int, int> p = {-1, -1};
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == t[0] && i%2 && p.first == -1) p.first = i;
            if(s[i] == t[0] && i%2 == 0 && p.second == -1) p.second = i;
            if(p.first != -1 && p.second != -1) break;
        }
        if((p.first != -1 && sol(p.first)) || (p.second != -1 && sol(p.second))) cout << "YES\n";
        else cout << "NO\n";
    }
}
