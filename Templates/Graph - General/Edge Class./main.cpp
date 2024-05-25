#include <bits/stdc++.h>

using namespace std;

/** find edge types in spanning tree of graph:
 *  tree edge - back edge - forward/cross edges
 *  visited[i] = 1 -> exploring, 2 -> finished */

vector<vector<int>> g;
vector<int> visited;
int n;

void edge_class(int i, int parent = -1) {
    visited[i] = 1;
    for (int adj: g[i]) {
        if (visited[adj] == 0) {
            edge_class(adj, i);
        }
        else if (visited[adj] == 1) {
            if (adj != parent) {
                /* Back Edge */
            }
        }
        else if (visited[adj] == 2) {
            /* Forward/Cross Edge */
        }
    }
    visited[i] = 2;
}
