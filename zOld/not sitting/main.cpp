#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, m; cin>>n>>m;
        vector<int> qt(n*m);
        vector<vector<int>> g(n, vector<int> (m));
        queue<pair<int, int>> q;
        g[n/2][m/2] = 1; q.push({n/2, m/2});
        if(n%2==0) g[n/2-1][m/2] = 1, q.push({n/2-1, m/2});
        if(m%2==0) g[n/2][m/2-1] = 1, q.push({n/2, m/2-1});
        if(n%2==0 && m%2==0) g[n/2-1][m/2-1] = 1, q.push({n/2-1, m/2-1});
        while(!q.empty()) {
            auto r = q.front(); q.pop();
            qt[g[r.first][r.second]]++;
            if(r.first > 0 && g[r.first-1][r.second] == 0) q.push({r.first-1, r.second}), g[r.first-1][r.second] = g[r.first][r.second]+1;
            if(r.first < n-1 && g[r.first+1][r.second] == 0) q.push({r.first+1, r.second}), g[r.first+1][r.second] = g[r.first][r.second]+1;
            if(r.second > 0 && g[r.first][r.second-1] == 0) q.push({r.first, r.second-1}), g[r.first][r.second-1] = g[r.first][r.second]+1;
            if(r.second < m-1 && g[r.first][r.second+1] == 0) q.push({r.first, r.second+1}), g[r.first][r.second+1] = g[r.first][r.second]+1;
        }
        for (int i = 1; i < n*m; ++i) qt[i] += qt[i-1];
        int d = n/2 + m/2, k = 1;
        for (int i = 0; i <= n*m - 1; ++i) {
            cout << d << " ";
            if(i+1 >= qt[k]) k++, d++;
        }
        cout << "\n";
    }
}
