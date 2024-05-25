#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> op;
vector<int> a;
int n;

void rec(int l, int r, int k, int fix) {
    if (r == l) {
        if (fix) {
            op.emplace_back(l, r);
        }
    } else {
        rec(l + 1, r, k - 1, fix);
        op.emplace_back(l, r);
        rec(l + 1, r, k - 1, 1);
    }
}

void addop(int l, int r) {
    for (int i = l; i <= r; ++i) {
        if (a[i] != 0) op.emplace_back(i, i);
    }
    rec(l, r, r - l, 0);
    op.emplace_back(l, r);
}

int main() {
    int ans = 0, k;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        int cnt = 0, s = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) cnt++;
            else {
                s += a[j];
                s += cnt * cnt;
                cnt = 0;
            }
        }
        if (s + cnt * cnt > ans) ans = s + cnt * cnt, k = i;
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (k & (1 << i)) {
            if (l == -1) l = i;
            r = i;
        } else if (l != -1) {
            addop(l, r);
            l = -1;
        }
    }
    if (l != -1) addop(l, r);
    cout << ans << " " << op.size() << "\n";
    for (auto p : op) cout << p.first + 1 << " " << p.second + 1 << "\n";
}
