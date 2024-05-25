#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<int> tin, low;
int timer;
int n, m;
vector<string> sheet;

bool dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            if (dfs(to, v)) return true;
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1) {
                return true;
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        return true;
    }
    return false;
}

bool find_art_points() {
    timer = 0;
    g = vector<vector<int>> (n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (sheet[i][j] == '#') {
                if (i > 0 && sheet[i - 1][j] == '#') g[i * m + j].push_back((i - 1) * m + j);
                if (j > 0 && sheet[i][j - 1] == '#') g[i * m + j].push_back(i * m + j - 1);
                if (i < n - 1 && sheet[i + 1][j] == '#') g[i * m + j].push_back((i + 1) * m + j);
                if (j < m - 1 && sheet[i][j + 1] == '#') g[i * m + j].push_back(i * m + j + 1);
            }
        }
    }
    visited.assign(g.size(), false);
    tin.assign(g.size(), -1);
    low.assign(g.size(), -1);
    for (int i = 0; i < g.size(); ++i) {
        if (!g[i].empty())
            return dfs(i);
    }
    return false;
}

int main() {
    cin >> n >> m;
    int ans = INT_MAX, cnt = 0;
    sheet = vector<string>(n);
    for (int i = 0; i < n; ++i) cin >> sheet[i];
    if (find_art_points()) {
        cout << 1;
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (sheet[i][j] == '#') {
                    cnt++;
                    int neigh =
                            (i > 0 && sheet[i - 1][j] == '#') +
                            (j > 0 && sheet[i][j - 1] == '#') +
                            (i < n - 1 && sheet[i + 1][j] == '#') +
                            (j < m - 1 && sheet[i][j + 1] == '#');
                    ans = min(ans, neigh);
                }
            }
        }
        cout << (cnt > 2 ? ans : -1);
    }
}
