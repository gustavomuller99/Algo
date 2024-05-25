#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 2, {0, INT_MAX});
    set<int> cur;
    set<int> lft;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].first;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].second;
    for (int i = 0; i <= n + 1; ++i)
        cur.insert(i), lft.insert(i);
    for (int i = 0; i < n; ++i) {
        set<int> del, n_cur;
        for (int p : cur) {
            auto it = lft.find(p);
            if (it == lft.end()) continue;
            int d = a[p].second;
            auto nxt = *next(it);
            auto prv = *prev(it);
            if (a[nxt].first + a[prv].first > d) {
                del.insert(p);
                n_cur.insert(nxt), n_cur.insert(prv);
            }
        }
        cur = n_cur;
        cout << del.size() << " ";
        for (int p : del) lft.erase(p);
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
