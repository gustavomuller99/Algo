#include <bits/stdc++.h>
using namespace std;

/*
 * algorithms for max matching in bipartite graph that run faster than
 * flow algorithms
 * */

/* kuhn algo
 * find augmenting paths */

int n, k;
vector<vector<int>> g;
vector<int> match, visited; //

int augmenting(int v) {
    if (visited[v])
        return 0;
    visited[v] = true;
    for (int to : g[v]) {
        if (match[to] == -1 || augmenting(match[to])) {
            match[to] = v;
            return 1;
        }
    }
    return 0;
}

void kuhn() {
    int mcbp = 0;

    match.assign(k, -1);
    for (int v = 0; v < n; ++v) {
        visited.assign(n, false);
        mcbp += augmenting(v);
    }

    for (int i = 0; i < k; ++i)
        if (match[i] != -1)
            printf("%d %d\n", match[i] + 1, i + 1);
}

/*
 * hopcroft karp
 * */
