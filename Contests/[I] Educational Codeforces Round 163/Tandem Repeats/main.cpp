#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 2; i <= s.size(); i += 2) {
        int diff = 0;
        for (int j = 0; j < i / 2; ++j) {
            if (s[j] != s[j + i / 2] && s[j] != '?' && s[j + i / 2] != '?') diff++;
        }
        if (diff == 0) ans = max(ans, i);
        for (int j = 1; j + i - 1 < s.size(); ++j) {
            if (s[j - 1] != s[j - 1 + i / 2] &&
                s[j - 1] != '?' &&
                s[j - 1 + i / 2] != '?')
                diff--;
            if (s[j + i / 2 - 1] != s[j + i - 1] &&
                s[j + i / 2 - 1] != '?' &&
                s[j + i - 1] != '?')
                diff++;
            if (diff == 0) ans = max(ans, i);
        }
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
