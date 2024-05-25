#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,ans=INT_MAX; cin>>n>>m;
    vector<vector<int>> g(n+m);
    vector<bool> v(n+m);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char c; cin>>c;
            if(c == '#') g[i].push_back(n+j), g[n+j].push_back(i);
        }
    q.push({n-1, 0}); v[n-1] = true;
    while(!q.empty()) {
        auto r = q.front(); q.pop();
        if(r.first == 0) ans = min(ans, r.second);
        for(int adj : g[r.first]) {
            if(!v[adj]) v[adj] = true, q.push({adj, r.second+1});
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);
}
