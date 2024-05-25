#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int>>> g;
vector<bool> visited;

void prim() {

    visited = vector<bool>(n);
    visited[0] = true;
    priority_queue<pair<int, int>> q;
    q.push({0, 0});
    int cost = 0;

    while (!q.empty()) {
        pair<int, int> front = q.top();
        q.pop();
        int u = front.second, w = -front.first;
        if (!visited[u]) {
            cost += w;
            visited[u] = true;
            /* add edge */
            for (auto adj: g[u]) {
                if (!visited[adj.first]) q.push({-adj.second, adj.first});
            }
        }
    }
}
