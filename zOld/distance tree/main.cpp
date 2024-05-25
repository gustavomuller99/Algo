#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> d;
vector<pair<int, int>> p;
int m;
void dfs(int i = 0, int dist = 0, int f = -1) {
    d[dist]++;
    if(p[dist].second != f) p[dist].first++;
    p[dist].second = f;
    m = max(m, dist);
    for(int adj: t[i]) {
        if(adj == f) continue;
        dfs(adj, dist + 1, i);
    }
}
int main() {
    int q; cin>>q; while(q--) {
        int n; cin>>n;
        t = vector<vector<int>> (n);
        d = vector<int> (n);
        p = vector<pair<int, int>> (n, {0, -1});
        m = 0;
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin>>u>>v; u--, v--;
            t[u].push_back(v), t[v].push_back(u);
        }
        dfs();
        for (int i = 1; i <= n; ++i) {
            if(i >= m) cout << m << " ";
            if(i + 1 == m && d[i + 1] == 1) cout << i << " ";
            if(i + 1 == m && d[i + 1] > 1) cout << i + 1 << " ";
            if(i + 1 < m && p[i + 2].f)
        }
    }
}
