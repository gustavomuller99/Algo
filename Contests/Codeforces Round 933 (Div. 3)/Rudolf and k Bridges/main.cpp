#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        vector<vector<ll>> map(n, vector<ll> (m)), dp(n, vector<ll> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            deque<ll> dq;
            multiset<ll> ms;
            for (int j = 0; j < m; ++j) {
                if (dq.size() > d + 1) {
                    ms.erase(ms.find(dq.front()));
                    dq.pop_front();
                }
                dp[i][j] = map[i][j] + 1;
                if (!ms.empty()) dp[i][j] += *ms.begin();
                ms.insert(dp[i][j]);
                dq.push_back(dp[i][j]);
            }
        }
        for (int i = 1; i < n; ++i) {
            dp[i][m - 1] += dp[i - 1][m - 1];
        }
        ll minv = LLONG_MAX;
        for (int i = k - 1; i < n; ++i) {
            minv = min(minv, dp[i][m - 1] - (i >= k ? dp[i - k][m - 1] : 0));
        }
        cout << minv << "\n";
    }
}