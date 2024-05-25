#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> d, p;
map<pair<int,int>, bool> m;
int dfs(int u=0, int f=-1, int dth=0, int inv=0) {
    int k = 0;
    d[u] = dth;
    p[u] = inv;
    for(int adj : t[u]) {
        if(adj == f) continue;
        k += dfs(adj, u, dth+1, inv + m[{adj, u}]);
    }
    return k + m[{u, f}];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    t.resize(n), d.resize(n), p.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        t[u].push_back(v), t[v].push_back(u);
        m[{u,v}] = true;
    }
    int ans = dfs(), inv = ans;
    vector<int> nodes;
    for (int i = 1; i < n; ++i) ans = min(ans, inv + d[i] - 2*p[i]);
    for (int i = 0; i < n; ++i) if(inv + d[i] - 2*p[i] == ans) nodes.push_back(i + 1);
    cout << ans << "\n";
    for(int nd : nodes) cout << nd << " ";
}
