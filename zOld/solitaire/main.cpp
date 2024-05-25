#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<int, pair<string, pair<string, string>>>, int> m;
int dfs(vector<string> c, int i = n-1) {
    string v = c[i];
    if(i > 1) {
        string vv = c[i-1]; string vvv = c[i-2];
        if(m[{i, {v, {vv, vvv}}}] != 0) return m[{i, {v, {vv, vvv}}}];
    }
    if(i == 0) return 2;
    int rt = 1;
    if(c[i-1][0] == c[i][0] || c[i-1][1] == c[i][1]) {
        string cp = c[i-1];
        c[i-1] = c[i];
        if(dfs(c, i-1) == 2) rt = 2;
        c[i-1] = cp;
    }
    if(i > 2 && (c[i-3][0] == c[i][0] || c[i-3][1] == c[i][1])) {
        string cp = c[i-3];
        c[i-3] = c[i];
        if(dfs(c, i-1) == 2) rt = 2;
        c[i-3] = cp;
    }
    if(i > 1) {
        string vv = c[i-1]; string vvv = c[i-2];
        m[{i, {v, {vv, vvv}}}] = rt;
    }
    return rt;
}
int main() {
    cin>>n;
    vector<string> c(n);
    for (int i = 0; i < n; ++i) cin>>c[i];
    cout << (dfs(c) == 2 ? "YES\n" : "NO\n");
}