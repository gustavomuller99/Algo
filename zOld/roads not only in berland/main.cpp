#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> tin, c;
vector<pair<int, int>> b;
int tt = 1;
void dfs(int n, int f = -1) {
    tin[n] = tt++;
    for(int adj: t[n]) {
        if(adj == f) continue;
        if(tin[adj] > tin[n])
            b.emplace_back(n, adj);
        if(tin[adj] == 0) dfs(adj, n);
    }
}
int main() {
    int n, cnt=0; cin>>n;
    t.resize(n); tin.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        t[u].push_back(v), t[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if(!tin[i]) c.push_back(i), cnt++, dfs(i);
    }
    cout << cnt - 1 << "\n";
    for (int i = 0; i < cnt - 1; ++i) {
        cout << b[i].first + 1 << " " << b[i].second + 1 << " " << c[i] + 1 << " " << c[i+1] + 1 << "\n";
    }
}
