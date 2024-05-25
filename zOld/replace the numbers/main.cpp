#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin>>q;
    vector<int> n(500001), a;
    vector<pair<int, int>> p(q);
    for (int i = 0; i < n.size(); ++i) n[i] = i;
    for (int i = 0; i < q; ++i) {
        int op, x, y; cin>>op;
        if(op == 1) cin>>x, p[i].first = x;
        else cin>>x>>y, p[i].first = x, p[i].second = y;
    }
    for (auto i = p.rbegin(); i != p.rend(); ++i) {
        if(i->second == 0) a.push_back(n[i->first]);
        else n[i->first] = n[i->second];
    }
    for (auto i = a.rbegin(); i != a.rend(); ++i) {
        cout << *i << " ";
    }
}
