#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g, p;
vector<vector<int>> t;
int n = 0;

/**
 * floyd marshall
 * cycle: adj[i][i] = INF
 * minmax / maxmim
 * diameter - max min distance in graph
 * scc -> t[i][j] & t[j][i]
 * */
void fm() {
    g.resize(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            p[i][j] = i;
        }
    }

    /* i == intermediate vertex */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (g[j][k] < g[j][i] + g[i][k]) {
                    g[j][k] = g[j][i] + g[i][k];
                    p[j][k] = p[i][k];
                }
            }
        }
    }
}


/** transitive closure */
void t_closure() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                t[j][k] |= t[j][i] & t[i][k];
            }
        }
    }
}
