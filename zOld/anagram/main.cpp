#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    string s,t; cin>>s>>t;
    vector<int> a(26), b(26), c(26), q(26);
    int ans = 0;
    for (char i : s) a[i-'A']++, q[i-'A']++;
    for (char i : t) b[i-'A']++;
    for (char & i : s) {
        c[i-'A']++;
        if(a[i-'A'] > b[i-'A']) {
            for (char j = 'A'; j <= 'Z'; ++j) {
                if(j < i && a[j-'A'] < b[j-'A'])
                    { a[j-'A']++, a[i-'A']--, ans++, i = j; break; }
                if(j > i && a[j-'A'] < b[j-'A'] && q[i-'A'] - c[i-'A'] < a[i-'A'] - b[i-'A'])
                    { a[j-'A']++, a[i-'A']--, ans++, i = j; break; }
            }
        }
    }
    cout << ans << "\n" << s;
}
