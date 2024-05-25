#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int dp[401][401];
int d;

int f(int x, int y) {
    if(x*x + y*y >= d*d) return 1;
    if(dp[x + 200][y + 200] != -1) return dp[x + 200][y + 200];
    for(auto p : v) {
        if(!f(x + p.first, y + p.second))
            return dp[x + 200][y + 200] = 1;
    }
    return dp[x + 200][y + 200] = 0;
}

int main() {
    int x,y,n;
    cin>>x>>y>>n>>d;
    v.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) cin>>v[i].first>>v[i].second;
    cout << (f(x, y) ? "Anton" : "Dasha");
}
