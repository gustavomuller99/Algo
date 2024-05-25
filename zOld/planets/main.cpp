#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> g;
map<pair<int,int>, int> mp;
vector<int> d;
int n, m;
void dj() {
    d.resize(n, INT_MAX); d[0] = mp[{0, 0}];
    priority_queue<pair<int, int>> p; p.push({-mp[{0, 0}], 0});
    while(!p.empty()) {
        int v = p.top().second, c = -p.top().first; p.pop();
        if(d[v] < -c) continue;
        for(auto adj: g[v]) {
            int cost = d[v] + adj.second + (adj.first == n-1 ? 0 : mp[{adj.first, d[v] + adj.second}]);
            if(d[adj.first] > cost) {
                d[adj.first] = cost;
                p.push({-cost, adj.first});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u,v,c; cin>>u>>v>>c; u--,v--;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    for (int i = 0; i < n; ++i) {
        int k, l=-2, cur; cin>>k;
        vector<int> a(k);
        for (int j = 0; j < k; ++j) cin>>a[j];
        for (int j = k-1; j >= 0; --j) {
            if(a[j] == l-1) cur++;
            else cur = 1;
            mp[{i, a[j]}] = cur;
            l = a[j];
        }
    }
    dj();
    cout << (d[n-1] == INT_MAX ? -1 : d[n-1]);
}
