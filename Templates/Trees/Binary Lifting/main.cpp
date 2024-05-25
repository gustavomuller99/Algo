#include <bits/stdc++.h>
using namespace std;

/**
* lowest common ancestor
* up[i][j] keeps the ancestor if i we go up 2^j nodes
* optional: keep the depth in d.
*
*/

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, depth;
vector<vector<int>> up;

void dfs(int v, int p, int dt)
{
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = dt;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
        /* add extra operation to keep other information like: min, max, sum, etc. */

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, dt + 1);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int go_up(int u, int h) {
    for (int i = l; i >= 0 ; --i) {
        if(1 << i <= h) {
            u = up[i][u];
            h -= 1 << i;
        }
    }
    return u;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root, 0);
}