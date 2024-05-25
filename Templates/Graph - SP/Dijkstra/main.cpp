#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int>>> g;
vector<int> p, dist;

void dijkstra() {
    dist.assign(n, INT_MAX);
    p.assign(n, -1);

    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != dist[v])
            continue;

        for (auto adj : g[v]) {
            int to = adj.first;
            int len = adj.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                p[to] = v;
                q.push({dist[to], to});
            }
        }
    }
}
