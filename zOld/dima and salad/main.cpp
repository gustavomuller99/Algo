#include <bits/stdc++.h>
using namespace std;
int P = 10000, M = 20004;
int main() {
    int n, k; cin>>n>>k;
    vector<pair<int, int>> f(n);
    for (int i = 0; i < n; ++i) cin>>f[i].first;
    for (int i = 0; i < n; ++i) cin>>f[i].second, f[i].second *= k;
    int d[n][M];
    memset(d, 0, sizeof(d));
    d[0][f[0].first - f[0].second + P] = f[0].first;
    for (int i = 1; i < n; ++i) {
        int diff = f[i].first - f[i].second;
        for (int j = 0; j < M; ++j) {
            d[i][j] = d[i-1][j];
            if(j - diff >= 0 && j - diff < M && d[i-1][j - diff])
                d[i][j] = max(d[i][j], d[i-1][j - diff] + f[i].first);
        }
        d[i][diff + P] = max(d[i][diff + P], f[i].first);
    }
    cout << (d[n-1][P] == 0 ? -1 : d[n-1][P]);
}
