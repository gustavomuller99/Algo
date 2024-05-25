#include <bits/stdc++.h>

using namespace std;

/**
 * kruskal for mst
 * */

struct Edge {
    int u, v, weight;

    bool operator<(Edge const &other) const {
        return weight < other.weight;
    }
};

vector<int> parent, size;
int n;
vector<Edge> edges;

void make_set(int v) {
    parent[v] = v;
    size[v] = 0;
}

int find_set(int v) {
    return (parent[v] == v ? v : parent[v] = find_set(parent[v]));
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        if (size[a] == size[b])
            size[a]++;
    }
}

void kruskal() {
    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    int cnt = 0;
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
            if (++cnt == n - 1) break;
        }
    }
}