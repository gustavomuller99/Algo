#include <bits/stdc++.h>
using namespace std;
vector<int> w;
vector<vector<pair<int, int>>> g;

void dfs(int u, int f = -1, int pr = 0) {
    for(auto adj : g[u]) {
        if(adj.first == f) continue;
        if(pr) w[adj.second] = 3;
        else w[adj.second] = 2;
        dfs(adj.first, u, !pr);
    }
}

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        g = vector<vector<pair<int, int>>> (n);
        w = vector<int> (n-1);
        for (int i = 0; i < n-1; ++i) {
            int u, y; cin>>u>>y; u--,y--;
            g[u].push_back({y, i}), g[y].push_back({u, i});
        }
        bool ans = true;
        int b;
        for (int i = 0; i < n; ++i) {
            if(g[i].size() > 2) ans = false;
            if(g[i].size() == 1) b = i;
        }
        if(!ans) cout << "-1\n";
        else {
            dfs(b);
            for (int i = 0; i < w.size(); ++i) cout << w[i] << " ";
        }
        cout << "\n";
    }
}
