#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<int> ans(n), in(n);
    set<int> s;
    map<int, pair<int, pair<int, int>>> m;
    for (int i = 0; i < n; ++i) {
        int x; cin>>x; m[x].first = i; in[i] = x;
        if(i == 0) s.insert(x);
    }
    for (int i = 1; i < n; ++i) {
        int k = in[i];
        auto r = s.upper_bound(k), l = r; l--;
        if(m[*r].second.first == 0 && r != s.end()) {
            m[*r].second.first = k;
            ans[m[k].first] = *r;
        } else {
            m[*l].second.second = k;
            ans[m[k].first] = *l;
        }
        s.insert(k);
    }
    for (int i = 1; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
