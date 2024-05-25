#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, d, ans = 0; cin>>n>>d;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) continue;
            int pos = (i+d)%n, f = -1;
            vector<int> p; p.push_back(a[i]);
            if(a[i] == 0) f = 0;
            while(pos != i) {
                p.push_back(a[pos]);
                if(a[pos] == 0 && f == -1) f = p.size() - 1;
                a[pos] = -1;
                pos = (pos + d) % n;
            }
            if(f == -1) ans = -1;
            else {
                f += p.size();
                for (int i = p.size()-1; i >= 0; --i) {
                    if(p[i] == 0) f = i;
                    if(ans != -1) ans = max(ans, f-i);
                }
            }
        }
        cout << ans << "\n";
    }
}
