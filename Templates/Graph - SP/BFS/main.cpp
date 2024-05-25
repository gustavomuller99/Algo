#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;
vector<vector<pair<int, int>>> gw;
vector<int> p, dist;

/**
 * unweighted / 0-1 -> bfs
 * */

void bfs() {
    dist.assign(n, INT_MAX);
    dist[0] = 0;
    queue<int> q;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int adj: g[u]) {
            if (dist[adj] == INT_MAX) {
                dist[adj] = dist[u] + 1;
                p[adj] = u;
                q.push(adj);
            }
        }
    }
}

void bfs01 () {
    dist.assign(n, INT_MAX);
    dist[0] = 0;
    deque<int> q;
    q.push_front(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto adj : gw[v]) {
            int u = adj.first;
            int w = adj.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}