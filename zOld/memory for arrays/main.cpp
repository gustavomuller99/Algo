#include <bits/stdc++.h>
using namespace std;
int B = 32;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, ans=0; cin>>n>>m;
    vector<int> b(B), a(m);
    for (int i = 0; i < n; ++i) {
        int x; cin>>x;
        for (int j = 0; j < B; ++j) {
            if((x >> j) % 2) b[j]++;
        }
    }
    for (int i = 0; i < m; ++i) cin>>a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        int l = -1;
        for (int j = a[i]; j < B; ++j) if(b[j]) {
            l = j; break;
        }
        if(l == -1) break;
        b[l]--;
        if(l != a[i]) for (int j = l-1; j >= a[i]; --j) b[j]++;
        ans++;
    }
    cout << ans;
}
