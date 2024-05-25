#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x; x--;
        vector<bool> has(n);
        set<int> cur;
        cur.insert(x);
        for (int i = 0; i < m; ++i) {
            int r; char dir;
            cin >> r >> dir;
            set<int> ncur;
            for(auto p : cur) {
                if (dir != '1') ncur.insert((p + r) % n);
                if (dir != '0') ncur.insert((p - r + n) % n);
            }
            cur = ncur;
        }
        cout << cur.size() << "\n";
        for(auto p : cur) {
            cout << p + 1 << " ";
        }
        cout << "\n";
    }
}
