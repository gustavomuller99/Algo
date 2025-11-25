#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p; cin>>n>>m>>p;
    int d[n][m][p][2];
    string a, b; cin>>a>>b;
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                d[i][j][k][0] = max(i ? d[i-1][j][k][0] : 0, j ? d[i][j-1][k][0] : 0);
                d[i][j][k][0] = max(d[i][j][k][0], i ? d[i-1][j][k][1] : 0);
                d[i][j][k][0] = max(d[i][j][k][0], j ? d[i][j-1][k][1] : 0);
                if(a[i] == b[j]) {
                    d[i][j][k][1] = ((k && j && i) ? d[i-1][j-1][k-1][0] : 0) + 1;
                    d[i][j][k][1] = max(d[i][j][k][1], ((i && j) ? d[i-1][j-1][k][1] : 0) + 1);
                }
            }
        }
    }
    int y = 4;
    cout << max(d[n-1][m-1][p-1][0], d[n-1][m-1][p-1][1]);
}
