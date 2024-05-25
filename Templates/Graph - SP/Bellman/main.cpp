#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int>>> g;
vector<int> p, dist;

void bellman() {
    dist.assign(n, INT_MAX);
    dist[0] = 0;
    for (;;) {
        bool any = false;

        for (int i = 0; i < n; ++i) {
            for (auto adj: g[i]) {
                if (dist[i] + adj.second < dist[adj.first]) {
                    dist[adj.first] = dist[i] + adj.second;
                    any = true;
                }
            }
        }
        if (!any)
            break;
    }
}
