#include <bits/stdc++.h>

using namespace std;

string s, t;

/*
 * edit distance, transform string s in t
 * differente weights for match, mismatch, delete and insert
 * result in different solutions
 * ex: lcs -> match = 1, delete = 0, insert = 0, mismatch = INF;
 */

void edit_distance() {
    int n = s.size(), m = t.size();
    int dp[n][m];
    memset(dp, 1e9, sizeof dp);
    for (int i = 0; i < n; ++i) dp[i][0] = i;
    for (int i = 0; i < m; ++i) dp[0][i] = i;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = min(dp[i - 1][j] + 1,
                           min(dp[i][j - 1], dp[i - 1][j - 1] + (s[i] != t[j])));
        }
    }
}
