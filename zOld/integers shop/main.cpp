#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, l = INT_MAX, r = 0;
        cin>>n;
        map<int, pair<int, int>> ll, rr;
        map<pair<int, int>, int> eq;
        for (int i = 0; i < n; ++i) {
            int lx, rx, c; cin>>lx>>rx>>c;
            auto a = ll[lx], b = rr[rx];
            auto e = eq[{lx, rx}];
            if(a.second == 0 || a.second > c) ll[lx] = {i, c};
            if(b.second == 0 || b.second > c) rr[rx] = {i, c};
            if(e == 0 || e > c) eq[{lx, rx}] = c;
            l = min(l, lx); r = max(r, rx);
            a = ll[l], b = rr[r], e = eq[{l, r}];
            cout << min(e == 0 ? INT_MAX : e, a.second + (a.first == b.first ? 0 : b.second)) << "\n";
        }
    }
}
