#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;
vector<bool> visited;
vector<int> tin, low;
int timer;

/**
 * find articulation points in O(V + E)
 * is articulation if low[to] >= tin[v] (no back edge to ancestral of v) */

void dfs0(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs0(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1) {
                /* v is articulation point */
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        /* p is articulation point */
    }
}

void find_art_points() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs0(i);
    }
}

/** find bridges in O(V + E)
 * v - to is bridge if low[to] > tin[v] (no back edge to v or ancestral) */

void dfs1(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs1(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                /* v - to is bridge */
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs1(i);
    }
}

/** find bridges online
 * edges can be added once at a time
 * complexity: O(VlogV + ElogV) */

