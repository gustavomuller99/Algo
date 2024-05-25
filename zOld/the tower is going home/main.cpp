#include <bits/stdc++.h>
using namespace std;
vector<int> v, h;
int main() {
    int n, m; cin>>n>>m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    for (int i = 0; i < m; ++i) {
        int x1, x2, y; cin>>x1>>x2>>y;
        if(x1 == 1) h.push_back(x2);
    }
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    int ans = v.size();
    for (int i = 0; i < h.size(); ++i) if(h[i] == 1e9) ans++;
    for (int i = 0; i < n; ++i) {
        int l = -1, r = h.size();
        while(l + 1 < r) {
            int mid = (l+r) / 2;
            if(h[mid] < v[i]) l = mid;
            else r = mid;
        }
        ans = min(ans, i + ((int) h.size() - r));
    }
    cout << ans;
}
