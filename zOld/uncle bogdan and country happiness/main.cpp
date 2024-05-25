#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> p, h;
void dfs1(int n = 0, int f = -1) {
    for (int adj: t[n]) {
        if(adj != f) dfs1(adj, n), p[n] += p[adj];
    }
}
bool dfs2(int n = 0, int f = -1) {
    bool r = true;
    int hp = (p[n] + h[n]) / 2;
    if((p[n] + h[n]) % 2 != 0 || hp < 0 || hp > p[n]) return false;
    int s = 0;
    for(int adj: t[n]) {
        if(adj == f) continue;
        r &= dfs2(adj, n);
        s += (p[adj] + h[adj]) / 2;
    }
    if(s > hp) r = false;
    return r;
}
int main() {
    int q; cin>>q; while(q--) {
        int n, m; cin>>n>>m;
        p = vector<int> (n); t = vector<vector<int>> (n); h = vector<int> (n);
        for (int i = 0; i < n; ++i) cin>>p[i];
        for (int i = 0; i < n; ++i) cin>>h[i];
        for (int i = 0; i < n-1; ++i) {
            int u, v; cin>>u>>v; u--,v--;
            t[u].push_back(v), t[v].push_back(u);
        }
        dfs1();
        cout << (dfs2() ? "YES\n" : "NO\n");
    }
}
