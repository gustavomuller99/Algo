#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> g(n);
        for (int i = 0; i < n; ++i) cin >> g[i];
        bool sol = g[0][0] != g[n - 1][m - 1] && g[n - 1][0] != g[0][m - 1];
        bool row = sol, col = sol;
        for (int i = 0; i < n; ++i) {
            if (g[i][0] != g[0][0]) col = false;
            if (g[i][m - 1] != g[0][m - 1]) col = false;
        }
        for (int i = 0; i < m; ++i) {
            if (g[0][i] != g[0][0]) row = false;
            if (g[n - 1][i] != g[n - 1][0]) row = false;
        }
        if (row || col) cout << "NO\n";
        else cout << "YES\n";
    }
}
