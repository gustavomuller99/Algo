#include <bits/stdc++.h>
using namespace std;

vector<int> d;
int g(int u) { return d[u] = d[u] == u ? u : g(d[u]); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<pair<int, pair<int,int>>> e;
        d.resize(n);
        for (int i = 0; i < n; ++i) d[i] = i;
        for (int i = 0; i < m; ++i) {
            int u,v,c; cin>>u>>v>>c; u--,v--;
            e.push_back({c-k, {u,v}});
        }
        sort(e.begin(), e.end());
        long long closest = INT_MAX, sum = 0;
        for (int i = 0; i < m; ++i) {
            auto r = e[i];
            if(g(r.second.first) != g(r.second.second)) {
                d[g(r.second.first)] = g(r.second.second);
                if(r.first > 0) sum += r.first;
            }
            if(abs(r.first) < closest) closest = abs(r.first);
        }
        if(sum > 0) cout << sum << "\n";
        else cout << closest << "\n";
    }
}
