#include <bits/stdc++.h>
using namespace std;

struct x { int u, t, i; };
vector<vector<x>> g;
vector<bool> vis;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, s, k = 0; cin>>n>>m>>s; s--;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, t; cin>>t>>u>>v, u--, v--;
        g[u].push_back({v, t == 2 ? 1 : 0, k});
        if(t == 2) g[v].push_back({u, -1, k++});
    }

    queue<int> q; q.push(s); vis = vector<bool>(n);
    vector<char> ans(k); int r1 = 0;
    while(!q.empty()) {
        int r = q.front(); q.pop();
        if(vis[r]) continue;
        vis[r] = true;
        r1++;
        for(auto x: g[r]) {
            if(x.t) {
                if(ans[x.i] != '+' && ans[x.i] != '-') ans[x.i] = x.t == 1 ? '+' : '-';
            }
            if(!vis[x.u]) q.push(x.u);
        }
    }
    cout << r1 << "\n";
    for (char an : ans) cout << (an == '+' || an == '-' ? an : '+');

    q.push(s); vis = vector<bool>(n);
    ans = vector<char>(k); r1 = 0;
    while(!q.empty()) {
        int r = q.front(); q.pop();
        if(vis[r]) continue;
        vis[r] = true;
        r1++;
        for(auto x: g[r]) {
            if(x.t) {
                if(ans[x.i] != '+' && ans[x.i] != '-') ans[x.i] = x.t == 1 ? '-' : '+';
            } else if(!vis[x.u]) q.push(x.u);
        }
    }
    cout << "\n" << r1 << "\n";
    for (char an : ans) cout << (an == '+' || an == '-' ? an : '+');
}
