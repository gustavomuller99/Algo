#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> p;
vector<int> a;
int l, r;

void bfs(int u) {
    queue<pair<int, int>> q;
    q.push({u, 0});
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        if (a[f.first] != 0) continue;
        a[f.first] = (f.second ? r-- : l++);
        for (auto adj : p[f.first]) {
            if (a[adj] == 0) q.push({adj, !f.second});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    p.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        p[u].push_back(v), p[v].push_back(u);
    }
    if (n == 1 || n * (n - 1) / 2 == m) cout << "NO\n";
    else {
        a.resize(n);
        l = 1, r = n;
        int in = 0;
        for (int i = 0; i < n; ++i) if (p[i].size() < p[in].size()) in = i;
        bfs(in);
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) bfs(i);
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; ++i) cout << (a[i] == 2 ? 1 : a[i]) << " ";
    }
}
