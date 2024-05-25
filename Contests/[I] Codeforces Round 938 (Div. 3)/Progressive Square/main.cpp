#include <bits/stdc++.h>

using namespace std;

map<int, int> m;

void solve() {
    m.clear();
    int n, c, d, l = INT_MAX;
    cin >> n >> c >> d;
    for (int i = 0; i < n * n; ++i) {
        int x;
        cin >> x;
        m[x]++;
        l = min(l, x);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int e = l + i * c + j * d;
            if (m[e] == 0) {
                cout << "NO\n";
                return;
            }
            m[e]--;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
