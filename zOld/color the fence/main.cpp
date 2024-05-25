#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, m = INT_MAX; cin>>v;
    vector<int> a(9), q(9);
    for (int i = 0; i < 9; ++i) cin>>a[i], m = min(a[i], m);
    int l = v / m;
    string ans; int cnt = 0;
    for (int i = 8; i >= 0; --i) {
        while(v - a[i] >= 0 && (v - a[i]) / m + cnt + 1 >= l)
            cnt++,
            ans.push_back('0' + i + 1),
            v -= a[i];
    }
    cout << (ans.empty() ? "-1" : ans);
}
