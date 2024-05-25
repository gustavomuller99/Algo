#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
map<pair<int, int>, int> a;
vector<vector<pair<int, ll>>> g;
vector<ll> d, p;
priority_queue<pair<ll, ll>> q;

void dj() {
    d.resize(n, LLONG_MAX); p.resize(n, -1);
    q.push({0, 0});
    d[0] = 0;
    while(!q.empty()) {
        auto r = q.top(); q.pop();
        if(-r.first != d[r.second]) continue;
        for(auto adj : g[r.second]) {
            if(d[r.second] + adj.second < d[adj.first]) {
                d[adj.first] = d[r.second] + adj.second; q.push({-d[adj.first], adj.first});
                p[adj.first] = r.second;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m>>k;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin>>u>>v>>w; u--,v--;
        g[u].emplace_back(v, w), g[v].emplace_back(u, w);
        a[{u, v}] = i+1;
    }
    dj();
    vector<int> ans;
    queue<int> b; b.push(0);
    while(!b.empty() && k) {
        auto r = b.front(); b.pop();
        for(auto adj: g[r]) {
            if (p[adj.first] == r) {
                k--; ans.push_back(a[{r, adj.first}] > 0 ?
                    a[{r, adj.first}] :
                    a[{adj.first, r}]);
                b.push(adj.first);
            }
            if(!k) break;
        }
    }
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
}
