#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, double>>> g;
vector<int> p;
bool f(double x) {
    vector<double> d(n, INT_MAX);
    vector<bool> iq(n, false);
    d[0] = 0;
    queue<int> q; q.push(0);
    iq[0] = true;
    while(!q.empty()) {
        int r = q.front(); q.pop();
        iq[r] = false;
        for(auto adj: g[r]) {
            if(d[adj.first] > d[r] + adj.second - x) {
                if(!iq[adj.first]) q.push(adj.first), iq[adj.first] = true;
                d[adj.first] = d[r] + adj.second - x;
                p[adj.first] = r;
            }
        }
    }
    return d[n-1] < 0;
}
int main() {
    cin>>n>>m;
    g.resize(n); p.resize(n);
    for (int i = 0; i < m; ++i) {
        int a,b,c; cin>>a>>b>>c; a--, b--;
        g[a].push_back({b, c});
    }
    double l = -1, r = 101;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    vector<int> ans; ans.push_back(n-1);
    int k = n-1;
    while(k != 0) {
        k = p[k];
        ans.push_back(k);
    }
    cout << ans.size() - 1 << "\n";
    for (auto i = ans.rbegin(); i < ans.rend(); ++i) {
        cout << *i + 1 << " ";
    }
}
