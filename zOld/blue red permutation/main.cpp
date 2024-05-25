#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n, l, r; cin>>n;
        string s;
        vector<pair<long long, char>> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i].first;
        cin >> s;
        for (int i = 0; i < n; ++i) a[i].second = s[i];
        sort(a.begin(), a.end());
        l = 1, r = n;
        for (int i = 0; i < n; ++i) {
            if(a[i].second == 'B' && a[i].first >= l) l++;
        }
        for (int i = n-1; i >= 0; --i) {
            if(a[i].second == 'R' && a[i].first <= r) r--;
        }
        if(l == r + 1) cout << "YES\n";
        else cout << "NO\n";
    }
}
