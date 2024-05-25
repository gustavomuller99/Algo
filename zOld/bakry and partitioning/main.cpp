#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<vector<int>> g;
bool ans; int x, ch;
int dfs(int op, int u = 0, int f = -1) {
    int xr = a[u];
    for(int adj: g[u]) {
        if(adj == f || adj == ch) continue;
        xr ^= dfs(op, adj, u);
    }
    if(u != 0 && op == 0 && xr == x && ch == -1) ch = u;
    if(u != 0 && op == 1 && xr == x && ch != -1) ans = true;
    return xr;
}

int main() {
    int t; cin>>t; while(t--) {
        int n, k; x=0, ch=-1; cin>>n>>k;
        a = vector<int> (n);
        g = vector<vector<int>> (n);
        for (int i = 0; i < n; ++i) cin>>a[i], x ^= a[i];
        for (int i = 0; i < n-1; ++i) {
            int u, v; cin>>u>>v; u--,v--;
            g[u].push_back(v), g[v].push_back(u);
        }
        ans = (x == 0);
        if(k > 2) {
            dfs(0), dfs(1);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
