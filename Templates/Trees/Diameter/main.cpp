#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> t;
int diameter;

pair<int, int> dfs(int n, int f = -1) {
    pair<int, int> r = {n, 1};
    for(int adj : t[n]) {
        if(adj == f) continue;
        auto rt = dfs(adj, n);
        if(rt.second >= r.second) {
            r.first = rt.first;
            r.second = rt.second + 1;
        }
    }
    return r;
}

void diam() {
    pair<int, int> a = dfs(0);
    pair<int, int> b = dfs(a.first);
    diameter = b.second - 1;
}
