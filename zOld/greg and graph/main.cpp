#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> g;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    g.resize(n, vector<long long> (n));
    vector<int> x(n), a(n);
    vector<unsigned long long> ans;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin>>g[i][j];
    for (int i = 0; i < n; ++i)
        cin>>x[i], x[i]--;

    for (int i = x.size()-1; i >= 0; --i) {
        a[x[i]] = true;
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k) {
                g[j][k] = min(g[j][k], g[j][x[i]] + g[x[i]][k]);
            }
        unsigned long long s = 0;
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if(a[j] && a[k]) s += g[j][k];
        ans.push_back(s);
    }
    for (int i = ans.size()-1; i >= 0; --i)
        cout << ans[i] << " ";

}
