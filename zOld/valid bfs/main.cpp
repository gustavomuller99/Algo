#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<vector<int>> g(n);
    vector<int> in(n);
    vector<bool> vis(n);
    queue<set<int>> bfs;
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) cin>>in[i],in[i]--;
    for (int i = 0; i < n; ++i) {
        if(i) {
            set<int> c = bfs.front(); bfs.pop();
            int j;
            for (j = i; j < i+c.size() && j < n; ++j) {
                set<int> s;
                if(!c.count(in[j])) {
                    cout << "NO";
                    return 0;
                }
                for(int adj : g[in[j]]) {
                    if(vis[adj]) continue;
                    vis[adj] = true;
                    s.insert(adj);
                }
                bfs.push(s);
            }
            i = j - 1;
        } else {
            if(in[i] != 0) {
                cout << "NO";
                return 0;
            }
            vis[in[i]] = true;
            set<int> s;
            for(int adj : g[in[i]]) {
                vis[adj] = true;
                s.insert(adj);
            }
            bfs.push(s);
        }
    }
    cout << "YES";
}
