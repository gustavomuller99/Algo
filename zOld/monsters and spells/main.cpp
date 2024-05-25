#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll sum(ll i) {
    return i*(i+1)/2;
}

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> k(n), h(n);
        vector<pair<int, int>> p;
        for (int i = 0; i < n; ++i) cin>>k[i];
        for (int i = 0; i < n; ++i) cin>>h[i];
        for (int i = 0; i < n; ++i) {
            pair<int, int> d = {k[i] - h[i] + 1, k[i]};
            while(!p.empty() && d.first <= p.back().second) {
                d = {min(d.first, p.back().first), d.second};
                p.pop_back();
            }
            p.push_back(d);
        }
        ll ans = 0;
        for (auto & i : p) {
            ans += sum(i.second - i.first + 1);
        }
        cout << ans << "\n";
    }
}
