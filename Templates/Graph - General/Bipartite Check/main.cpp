#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> side;
int n;

/** bicolors a graph, if possible */

/*
 * MCBM - maximum cardinality bipartite matching
 * max matching -> cap = 1
 * MIS = V - MCBM (maximum independent set)
 * MVC = MCBM (min vertex cover) 
 */

void bipartite() {
    side = vector<int>(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : g[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
}
