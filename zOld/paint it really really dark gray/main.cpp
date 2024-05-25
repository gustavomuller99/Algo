#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> t;
vector<int> c, p, cnt;

int dfs1(int u, int f = -1) {
    for (int adj: t[u]) {
        if (adj != f) cnt[u] += dfs1(adj, u);
    }
    return cnt[u] += c[u];
}

void dfs2(int u, int f = -1) {
    p.push_back(u);
    c[u] = !c[u];
    for (int adj : t[u]) {
        if (adj == f || cnt[adj] == 0) continue;
        dfs2(adj, u);
        p.push_back(u);
        c[u] = !c[u];
        if (c[adj]) {
            p.push_back(adj), p.push_back(u);
            c[u] = !c[u];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    c.resize(n), t.resize(n);
    cnt.resize(n);
    for (int i = 0; i < n; ++i) {
        int cl;
        cin >> cl;
        c[i] = cl == -1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        t[u].push_back(v), t[v].push_back(u);
    }
    c[0] = !c[0];
    dfs1(0), dfs2(0);
    if (c[0]) {
        p.push_back(t[0][0]);
        p.push_back(0);
        p.push_back(t[0][0]);
    }
    for (int i : p) cout << i + 1 << " ";
}
