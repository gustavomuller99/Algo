#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    bool ans = true;
    vector<int> u(n+1), f(n), g(n), h;
    for (int i = 0; i < n; ++i) cin>>f[i], u[f[i]] = 1;
    for (int i = 0; i < n; ++i) if(f[i] == i + 1) u[i + 1] = 0;
    for (int i = 0; i <= n; ++i) if(u[i]) ans = false;
    if(!ans) cout << "-1";
    else {
        vector<int> l(n+1);
        for (int i = 0; i < n; ++i) {
            if(l[f[i]] == 0) {
                h.emplace_back();
                l[f[i]] = h.size();
            }
            g[i] = l[f[i]];
            if(f[i] == i + 1) h[l[f[i]] - 1] = i + 1;
        }
        cout << h.size() << "\n";
        for(int x : g) cout << x << " "; cout << "\n";
        for(int x : h) cout << x << " ";
    }
}
