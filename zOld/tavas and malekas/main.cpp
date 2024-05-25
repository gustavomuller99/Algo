#include <bits/stdc++.h>
using namespace std;
unsigned long long mod = 1e9+7;
vector<int> p;
set<int> pref;
void kmp(const string& s) {
    p.resize(s.size()); p[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j])
            j = p[j-1];
        if(s[i] == s[j])
            j++;
        p[i] = j;
    }

    int j = s.size();
    while(j > 0) {
        pref.insert(p[j-1]);
        j = p[j-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin>>n>>m;
    string s; cin>>s; kmp(s);
    vector<int> y(m);
    for (int i = 0; i < m; ++i) cin>>y[i], y[i]--;
    int l = -1, f = 0;
    for (int i = 0; i < m; ++i) {
        f += s.size() - (l >= y[i] ? (l - y[i] + 1) : 0);
        if(l >= y[i] && !pref.count(l - y[i] + 1)) {
            cout << 0; exit(0);
        }
        l = y[i] + s.size() - 1;
    }
    unsigned long long ans = 1;
    for (int i = 0; i < n - f; ++i) {
        ans *= 26;
        ans %= mod;
    }
    cout << ans;
}
