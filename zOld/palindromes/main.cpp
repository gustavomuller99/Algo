#include <bits/stdc++.h>
using namespace std;
int c[501][501];
pair<int, int> d[501][501];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s; cin>>s;
    int k; cin>>k;
    for (int i = 0; i < s.size(); ++i)
        for (int j = i + 1; j < s.size(); ++j)
            for (int l = i; l < i + (j - i + 1) / 2; ++l)
                if(s[l] != s[j-(l-i)]) c[i][j]++;
    for (int i = 0; i < s.size(); ++i) d[i][0] = {c[0][i], -1};
    for (int i = 1; i <= k; ++i) {
        for (int j = i; j < s.size(); ++j) {
            d[j][i] = {INT_MAX, INT_MAX};
            for (int l = 1; l <= j; ++l) {
                if(d[l-1][i-1].first + c[l][j] <= d[j][i].first)
                    d[j][i] = {d[l-1][i-1].first + c[l][j], l - 1};
            }
        }
    }
    int ans = INT_MAX, i, l = s.size() - 1;
    vector<string> p;
    for (int j = 0; j < k; ++j) if(d[s.size()-1][j].first < ans) ans = d[s.size()-1][j].first, i = j;
    while(i >= 0) {
        string x;
        for (int j = d[l][i].second + 1; j < d[l][i].second + 1 + (l - d[l][i].second) / 2 + (l - d[l][i].second) % 2; ++j)
            x += s[j];
        for (int j = d[l][i].second + (l - d[l][i].second) / 2; j >= d[l][i].second + 1; --j)
            x += s[j];
        p.push_back(x);
        l = d[l][i].second;
        i--;
    }
    cout << ans << "\n";
    for (int j = p.size() - 1; j >= 0; --j) {
        cout << p[j];
        if(j) cout << "+";
    }
}
