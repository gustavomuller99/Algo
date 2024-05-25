#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> v;
int n, ans;
void dfs(int u) {
    v[u] = true;
    ans++;
    for(int adj : g[u]) if(!v[adj]) dfs(adj);
}
int main() {
    int t; cin>>t; while(t--) {
        cin >> n; ans = 0;
        string a, b;
        cin >> a >> b;
        g = vector<vector<int>> (20);
        v = vector<bool> (20);
        bool p = true;
        for (int i = 0; i < n; ++i) {
            if(a[i] > b[i]) p = false;
            g[a[i]-'a'].push_back(b[i]-'a');
            g[b[i]-'a'].push_back(a[i]-'a');
        }
        if(!p) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < 20; ++i) {
            if(!v[i]) {
                dfs(i), ans--;
            }
        }
        cout << ans << "\n";
    }
}
