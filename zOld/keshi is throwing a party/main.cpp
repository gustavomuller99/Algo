#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> p;
bool f(int x) {
    int cnt = 0, b = 0, a = x-1;
    for (auto & i : p) {
        if(i.first >= a && i.second >= b) cnt++, a--, b++;
    }
    return cnt >= x;
}
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        p = vector<pair<int, int>> (n);
        for (int i = 0; i < n; ++i) {
            cin>>p[i].first>>p[i].second;
        }
        int l = 0, r = n+1;
        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            if(f(mid)) l = mid;
            else r = mid;
        }
        cout << l << "\n";
    }
}
