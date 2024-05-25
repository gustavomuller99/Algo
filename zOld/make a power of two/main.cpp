#include <bits/stdc++.h>
using namespace std;

string a(unsigned long long x) {
    string s;
    while(x) s += '0' + x % 10, x /= 10;
    return string(s.rbegin(), s.rend());
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<string> p;
    int k = 0;
    while(k < 64) p.push_back(a(1ULL << k)), k++;
    int t; cin>>t; while (t--) {
        int ans = INT_MAX;
        string s; cin>>s;
        for(string x : p) {
            int r = 0, l = 0;
            for (int i = 0; i < s.size(); ++i) {
                if(s[i] == x[l]) l++;
                else r++;
            }
            ans = min(ans, r + (int) x.size() - l);
        }
        cout << ans << "\n";
    }
}
