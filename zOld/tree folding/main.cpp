#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;

int farthest = 0;
pair<int, int> c = {-1, -1};
int dfs(int u, int f = -1, int d = 0) {
    farthest = u;
    int m = d;
    for(int adj: t[u])
        if(adj != f) m = max(m, dfs(adj, u, d+1));
    if(d == m/2 || (m % 2 && d == m/2+1)) {
        if(c.first == -1) c.first = u;
        else c.second = u;
    }
    return m;
}

void center() {
    dfs(0);
    c = {-1, -1};
    dfs(farthest);
}

int dfs2(int u, int f = -1) {
    set<int> ch;
    for(int adj : t[u]) {
        if(adj != f) {
            int r = dfs2(adj, u);
            if(r == -1) return -1;
            ch.insert(r);
            if(ch.size() > 2) return -1;
        }
    }
    if((ch.size() == 2 && f == -1) || ch.size() < 2)
        return accumulate(ch.begin(), ch.end(), 0) + 1;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    t.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin>>u>>v; u--,v--;
        t[u].push_back(v), t[v].push_back(u);
    }
    center();
    int l = dfs2(c.first) - 1;
    while(l % 2 == 0) l /= 2;
    cout << l;
}