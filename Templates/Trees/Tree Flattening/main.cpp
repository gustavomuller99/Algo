#include <bits/stdc++.h>
using namespace std;

/**
 * flatten the tree with EULER TOUR
 * keep timer of in and out time and do range queries for subtrees
 * range of subtree is tin[i] ~ tout[i]  ^^^^^^^^
 */

vector<vector<int>> adj;

int n, timer;
vector<int> tin, tout;

void dfs1(int v, int p)
{
    tin[v] = ++timer;
    for (int u : adj[v]) {
        if (u != p)
            dfs1(u, v);
    }
    tout[v] = timer;
}

/**
 * path query for operations with inverse,
 * ex: sum, sub, mult, div, xor
 * query from i to j == tin[i] to tin[j]
 * */

void dfs2(int v, int p)
{
    tin[v] = ++timer;
    for (int u : adj[v]) {
        if (u != p)
            dfs2(u, v);
    }
    tout[v] = ++timer;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    dfs1(root, root);
}
