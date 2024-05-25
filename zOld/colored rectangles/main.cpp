#include <bits/stdc++.h>
using namespace std;

int main() {
    int r,g,b;
    cin>>r>>g>>b;
    vector<int> pr(r), pg(g), pb(b);
    for (int i = 0; i < r; ++i) cin>>pr[i]; sort(pr.begin(), pr.end(), greater<>());
    for (int i = 0; i < g; ++i) cin>>pg[i]; sort(pg.begin(), pg.end(), greater<>());
    for (int i = 0; i < b; ++i) cin>>pb[i]; sort(pb.begin(), pb.end(), greater<>());
    int d[r+1][g+1][b+1];
    memset(d, 0, sizeof d);
    int ans = 0;
    for (int i = 0; i <= r; ++i) {
        for (int j = 0; j <= g; ++j) {
            for (int k = 0; k <= b; ++k) {
                if(i < r && j < g) d[i+1][j+1][k] = max(d[i+1][j+1][k], d[i][j][k] + pr[i]*pg[j]);
                if(i < r && k < b) d[i+1][j][k+1] = max(d[i+1][j][k+1], d[i][j][k] + pr[i]*pb[k]);
                if(j < g && k < b) d[i][j+1][k+1] = max(d[i][j+1][k+1], d[i][j][k] + pg[j]*pb[k]);
                ans = max(ans, d[i][j][k]);
            }
        }
    }
    cout << ans;
}
