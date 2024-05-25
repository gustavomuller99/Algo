#include <bits/stdc++.h>

using namespace std;

int main() {
    int w;
    cin >> w;
    while (w--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        map<int, vector<int>> x;
        x[0].push_back(0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (i) a[i] ^= a[i - 1];
            x[a[i]].push_back(i);
        }
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            if (a[r] == a[l - 1]) cout << "YES\n";
            else {
                int s, t, ls = -1, rs = x[a[r]].size() - 1, lt = 0, rt = x[a[l - 1]].size();
                while (ls + 1 < rs) {
                    int mid = (ls + rs) / 2;
                    if (x[a[r]][mid] < l) ls = mid;
                    else rs = mid;
                }
                s = x[a[r]][rs] + 1;
                while (lt + 1 < rt) {
                    int mid = (lt + rt) / 2;
                    if (x[a[l - 1]][mid] > r) rt = mid;
                    else lt = mid;
                }
                t = x[a[l - 1]][lt];
                if (l < s && s <= t && t < r) cout << "YES\n";
                else cout << "NO\n";
            }
        }
        cout << "\n";
    }
}
