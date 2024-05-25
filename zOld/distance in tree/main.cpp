#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int n,k,ans=0;
vector<int> dfs(int u=0, int f=-1) {
    vector<int> h(501);
    for(int adj : g[u]) {
        if(adj != f) {
            vector<int> t = dfs(adj, u);
            ans += t[k];
            for (int i = 1; i < k; ++i) {
                ans += h[i] * t[k-i];
            }
            for (int i = 0; i < 501; ++i) h[i] += t[i];
        }
    }
    for (int i = 500; i >= 1; --i) h[i] = h[i-1];
    h[1] = 1;
    return h;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>k;
    g.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs();
    cout << ans;
}
