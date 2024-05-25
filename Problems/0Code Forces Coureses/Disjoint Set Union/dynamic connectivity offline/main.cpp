#include <bits/stdc++.h>
using namespace std;

vector<int> d, sz, p;
map<pair<int, int>, pair<int, int>> query;
stack<pair<int, int>> s;
int cc = 0;

int g(int u) { return d[u] == u ? u : g(d[u]); }

void persist() {
    s.push({p.size(), cc});
}

void rollback() {
    auto top = s.top(); s.pop();
    cc = top.second;
    while(p.size() != top.first) {
        int x = p.back(), v = g(x); p.pop_back();
        sz[v] -= sz[x];
        d[x] = x;
    }
}

void join(int u, int v) {
    u = g(u), v = g(v);
    if(u != v) {
        if(sz[u] > sz[v]) swap(u, v);
        sz[v] += sz[u];
        d[u] = v;
        p.push_back(u);
        cc--;
    }
}

void dco(int l, int r) {
    persist();
    for(auto x : query) {
        if(x.second.first <= l && x.second.second >= r) join(x.first.first, x.first.second);
    }
    if (l == r) {
        for (auto & i : query) {
            if(i.first.first == l && i.first.second == -1) i.second.first = cc;
        }
        rollback();
        return;
    }
    int m = (l + r) / 2;
    dco(l, m);
    dco(m+1, r);
    rollback();
}

int main() {
    int n, m; cin>>n>>m;
    d.resize(n), sz.resize(n, 1);
    cc = n;
    for (int i = 0; i < n; ++i) d[i] = i;
    for (int i = 1; i <= m; ++i) {
        char c; cin>>c;
        if(c == '?') query[{i, -1}];
        if(c == '+') {
            int u, v; cin>>u>>v; u--, v--;
            if(u < v) swap(u, v);
            query[{u, v}].first = i;
            if(query[{u, v}].second == 0)
                query[{u, v}].second = INT_MAX;
        }
        if(c == '-') {
            int u, v; cin>>u>>v; u--, v--;
            if(u < v) swap(u, v);
            query[{u, v}].second = i;
            if(query[{u, v}].first == 0)
                query[{u, v}].first = INT_MIN;
        }
    }
    dco(1, m);
    for(auto x : query) {
        if(x.first.second == -1) cout << x.second.first << "\n";
    }
}
