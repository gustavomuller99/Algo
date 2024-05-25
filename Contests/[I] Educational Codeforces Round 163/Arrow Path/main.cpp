#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> g;
vector<vector<int>> visited;

bool dfs(int i, int j, bool p = true) {
    if (i > 1 || i < 0 || j > n - 1 || j < 0) return false;
    if (p) {
        if (i == 1 && j == n - 1) return true;
        if (visited[i][j]) return false;
        visited[i][j] = 1;
        return dfs(i + 1, j, !p) ||
               dfs(i - 1, j, !p) ||
               dfs(i, j - 1, !p) ||
               dfs(i, j + 1, !p);
    } else {
        return (g[i][j] == '<' ? dfs(i, j - 1, !p) : dfs(i, j + 1, !p));
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        g = vector<string>(2);
        visited = vector<vector<int>>(2, vector<int>(n));
        cin >> g[0] >> g[1];
        if (dfs(0, 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
