#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> d(2);
        int x;
        cin >> x;
        d[0].push_back(x);
        if (x > 9 && (x / 10) % 10 <= x % 10) d[1].push_back((x / 10) % 10), d[1].push_back(x % 10);
        else d[1].push_back(x);
        for (int i = 0; i < n - 1; ++i) {
            cin >> x;
            for (int j = 0; j < 2; ++j) {
                if (x > 9 && d[j].back() <= (x / 10) % 10 && (x / 10) % 10 <= x % 10) {
                    d[j].push_back((x / 10) % 10), d[j].push_back(x % 10);
                } else d[j].push_back(x);
            }
        }
        int cnt = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j < d[i].size(); ++j) {
                if (d[i][j] < d[i][j - 1]) {
                    cnt++;
                    break;
                }
            }
        }
        if (cnt == 2) cout << "NO\n";
        else cout << "YES\n";
    }
}
