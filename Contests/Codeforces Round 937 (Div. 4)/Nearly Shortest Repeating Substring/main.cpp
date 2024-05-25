#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            string c = s.substr(0, i);
            int diff = 0, idx;
            for (int j = 0; j < n; ++j) {
                if (s[j] != c[j % i]) {
                    diff++;
                    idx = j;
                }
            }
            if (diff < 2) {
                cout << i << "\n";
                return;
            }
            c[idx % i] = s[idx];
            diff = 0;
            for (int j = 0; j < n; ++j) {
                if (s[j] != c[j % i]) {
                    diff++;
                    idx = j;
                }
            }
            if (diff < 2) {
                cout << i << "\n";
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}