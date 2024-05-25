#include <bits/stdc++.h>

using namespace std;

/*
 * path that goes through every edge once
 */

vector<int> euler;
vector<vector<pair<int, bool>>> g;

void euler_path(int u) {
    stack<int> s;
    vector<int> deg(g.size());

    for (int i = 0; i < g.size(); ++i) {
        deg[i] += g[i].size();
    }
    s.push(u);

    while (!s.empty()) {
        int top = s.top();
        if (deg[top] == 0) {
            euler.push_back(top);
            s.pop();
        } else {
            for (auto & i : g[top]) {
                if (i.second) {
                    i.second = false;
                    s.push(i.first);
                    break;
                }
            }
        }
    }
}
