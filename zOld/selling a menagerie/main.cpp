#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), c(n), d(n), v(n), ans;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
            d[a[i]]++;
        }
        for (int i = 0; i < n; ++i) cin >> c[i];
        for (int i = 0; i < n; ++i) if (d[i] == 0) q.push(i);
        while (!q.empty()) {
            int f = q.front(); q.pop();
            ans.push_back(f + 1);
            d[a[f]]--;
            if (d[a[f]] == 0) q.push(a[f]);
        }
        for (int i = 0; i < n; ++i) {
            if (d[i] != 0 && !v[i]) {
                q = queue<int>(); q.push(i);
                vector<int> add;
                int m = -1;
                while(!q.empty()) {
                    int f = q.front(); q.pop();
                    v[f] = true;
                    add.push_back(f);
                    if (m == -1 || c[f] < c[add[m]]) m = add.size() - 1;
                    if (!v[a[f]]) q.push(a[f]);
                }
                for (int j = 0; j < add.size(); ++j) {
                    ans.push_back(add[(m + j + 1) % add.size()] + 1);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}