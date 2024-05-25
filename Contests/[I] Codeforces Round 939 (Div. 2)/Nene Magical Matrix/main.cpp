#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int s = 0;
        vector<pair<int, int>> ans;
        vector<vector<int>> g(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            ans.emplace_back(1, n - i);
            ans.emplace_back(2, n - i);
        }

        for (auto p: ans) {
            if (p.first == 1) for (int i = 0; i < n; ++i) g[p.second - 1][i] = i + 1;
            else for (int i = 0; i < n; ++i) g[i][p.second - 1] = i + 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                s += g[i][j];
            }
        }

        cout << n * (2 * n - 1) << " " << ans.size() << "\n";
        for (auto p: ans) {
            cout << p.first << " " << p.second << " ";
            for (int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}
