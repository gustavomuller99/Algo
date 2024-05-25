#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> g;
int n;

/* improvement from bellman-ford, tries to relax only vertices
 * that were previously relaxed.
 * (unrelaxed vertices won't relax any other vertices)
 * */

void spfa() {
    vector<int> d(n, INT_MAX), p(n);
    vector<bool> iq(n, false); /* in queue */
    queue<int> q;

    q.push(0); iq[0] = true;
    while(!q.empty()) {
        int r = q.front(); q.pop();
        iq[r] = false;
        for(auto adj: g[r]) {
            if(d[adj.first] > d[r] + adj.second) {
                if(!iq[adj.first]) q.push(adj.first), iq[adj.first] = true;
                d[adj.first] = d[r] + adj.second;
                p[adj.first] = r;
            }
        }
    }
}
