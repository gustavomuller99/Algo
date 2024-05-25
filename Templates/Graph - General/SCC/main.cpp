#include <bits/stdc++.h>

using namespace std;

/** kosaraju for scc
 * gt - graph transversal */

int n, m;
vector<vector<int>> g, gt;
vector<int> used, order;
vector<vector<int> > comp;

/* dfs for computing exit time - toposort */
void dfs1(int u) {
    used[u] = true;
    for (auto v : g[u]) if (!used[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u) {
    used[u] = false;
    comp.back().push_back(u);
    for (auto v: gt[u]) if (used[v]) dfs2(v);
}

void kosaraju() {
    for (int i = 0; i < n; ++i) if (!used[i]) dfs1(i);
    reverse(order.begin(), order.end());
    for (auto v : order) {
        if (used[v]) {
            comp.emplace_back();
            dfs2(v);
        }
    }
}

/** tarjan for scc */
vector<int> tin, low, s, current;
int timer = 0;

void dfs(int u) {
    low[u] = tin[u] = timer++;
    s.push_back(u);
    current[u] = true;
    for (int adj: g[u]) {
        if (tin[adj] == -1) dfs(adj);
        if (current[adj]) low[u] = min(low[u], low[adj]);
    }
    if (low[u] == tin[u]) {
        comp.emplace_back();
        while (true) {
            int v = s.back();
            s.pop_back();
            current[v] = false;
            comp.back().push_back(v);
            if (u == v) break;
        }
    }
}

void tarjan() {
    tin = vector<int>(n, -1);
    low = vector<int>(n, -1);
    current = vector<int>(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!current[i]) dfs(i);
    }
}
