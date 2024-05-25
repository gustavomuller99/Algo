#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> p;
int n,m;
bool f(int x) {
    bool a = false, b = true;
    for (int j = 0; j < m; ++j) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) cnt += p[i][j] >= x;
        b &= cnt > 0;
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) cnt += p[i][j] >= x;
        a |= cnt > 1;
    }
    return a && b;
}
int main() {
    int t; cin>>t; while(t--) {
        cin>>n>>m;
        p = vector<vector<int>> (n, vector<int> (m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin>>p[i][j];
        int l = 1, r = 1e9+1;
        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            if(f(mid)) l = mid;
            else r = mid;
        }
        cout << l << "\n";
    }
}
