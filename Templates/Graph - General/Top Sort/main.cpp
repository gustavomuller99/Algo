#include <bits/stdc++.h>

using namespace std;

/**
 * topological sort of a dag
 * if not dag, v ~> u but u ~/> v, v always comes first
 * */

int n;
vector<vector<int>> g;
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

/** kahn's algorithm: uses outgoing degrees */
void kahn_topological_sort() {
    ans.clear();
    vector<int> deg = vector<int>(n, 0);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        for (int u: g[i]) deg[u]++;
    }
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v: g[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
}
