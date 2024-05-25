#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> c;
void dfs(int u, int col) {
    c[u] = col;
    for(int adj: g[u]) {
        if(c[adj] == 0) dfs(adj, col);
    }
}
int main() {
    int n, m, col=2; cin>>n>>m;
    g.resize(n); c.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin>>u>>v; u--,v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if(g[i].size() == n-1) c[i] = 1;
    }
    vector<int> cnt(4);
    for (int i = 0; i < n; ++i) {
        if(c[i] == 0) dfs(i, col), col++;
        if(c[i] < 4) cnt[c[i]]++;
    }
    bool check = false;
    for (int i = 0; i < n; ++i) {
        if(c[i] == 2 && g[i].size() != cnt[2] + cnt[1] - 1) check = true;
        if(c[i] == 3 && g[i].size() != cnt[3] + cnt[1] - 1) check = true;
    }
    if(col > 4 || check) cout << "No";
    else {
        cout << "Yes\n";
        for (int i = 0; i < n; ++i) {
            if(c[i] == 1) cout << "b";
            if(c[i] == 2) cout << "a";
            if(c[i] == 3) cout << "c";
        }
    }
}