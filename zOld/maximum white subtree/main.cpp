#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> c, ans;
void dfs1(int n = 0, int f = -1) {
    ans[n] += (c[n] == 0 ? -1 : 1);
    for(int adj: t[n]) {
        if(adj == f) continue;
        dfs1(adj, n);
        if(ans[adj] > 0) ans[n] += ans[adj];
    }
}
void dfs2(int n = 0, int f = -1) {
    if(f != -1) {
        int r = ans[f];
        if(ans[n] > 0) r -= ans[n];
        if(r > 0) ans[n] += r;
    }
    for(int adj: t[n]) {
        if(adj != f) dfs2(adj, n);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    t.resize(n); c.resize(n); ans.resize(n);
    for (int i = 0; i < n; ++i) cin>>c[i];
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin>>u>>v; u--, v--;
        t[u].push_back(v), t[v].push_back(u);
    }
    dfs1();
    dfs2();
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
