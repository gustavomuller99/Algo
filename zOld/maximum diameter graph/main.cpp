#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, l = 0, f = 0, cnt = 0, diam = 0; cin>>n;
    vector<int> d(n), c(n);
    vector<pair<int, int>> ans;
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        int x; cin>>x; q.push({x, i}); d[i] = x;
    }
    l = q.top().second; f = l; q.pop(); cnt++; c[l] = 1;
    while(!q.empty()) {
        auto r = q.top(); q.pop();
        cnt++; diam++; d[l]--, d[r.second]--; c[r.second] = 1;
        ans.emplace_back(l, r.second);
        if(r.first == 1) break;
        l = r.second;
    }
    if(!q.empty() && d[f]) {
        cnt++; diam++; d[f]--, d[q.top().second]--; c[q.top().second] = 1;
        ans.emplace_back(f, q.top().second);
        q.pop();
    }
    while(!q.empty()) {
        auto r = q.top(); q.pop();
        for (int i = 0; i < n; ++i) {
            if(d[i] && c[i]) {
                cnt++; d[i]--; d[r.second]--; c[r.second] = 1;
                ans.emplace_back(r.second, i);
                break;
            }
        }
    }
    if(cnt == n) {
        cout << "YES " << diam << "\n";
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x.first+1 << " " << x.second+1 << "\n";
    } else cout << "NO\n";
}
