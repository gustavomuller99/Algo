#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/gym/344975/problem/I

int n, m;

bool valid(int msk1, int msk2) {
    for (int i = 0; i < n - 1; ++i) {
        int m11 = msk1 & (1 << i) ? 1 : 0, m12 = msk1 & (1 << (i + 1)) ? 1 : 0;
        int m21 = msk2 & (1 << i) ? 1 : 0, m22 = msk2 & (1 << (i + 1)) ? 1 : 0;
        if ((m11 + m12 + m21 + m22) % 2 == 0) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    if (n > 3) {
        cout << -1;
        return 0;
    }
    vector<int> a(m);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            int b = s[j] - '0';
            a[j] += (b << i);
        }
    }
    vector<vector<int>> d(m, vector<int>(1 << n, INT_MAX));
    for (int i = 0; i < 1 << n; ++i) {
        d[0][i] = __builtin_popcount(a[0] ^ i);
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < 1 << n; ++j) {
            for (int k = 0; k < 1 << n; ++k) {
                if (valid(j, k)) d[i][k] = min(d[i][k], d[i - 1][j] + __builtin_popcount(a[i] ^ k));
            }
        }
    }
    int minv = INT_MAX;
    for (int i = 0; i < 1 << n; ++i) {
        minv = min(d[m - 1][i], minv);
    }
    cout << minv;
}
