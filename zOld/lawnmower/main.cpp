#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int pos = 0, d = 0;
    for (int i = 0; i < n; ++i) {
        int f = -1, l = 0;
        for (int j = 0; j < s[i].size(); ++j) {
            if (s[i][j] == 'W' && f == -1) f = j;
            if (s[i][j] == 'W') l = j;
        }
        if (f != -1) {
            d = i;
            if (i % 2) {
                if (i) ans += abs(pos - l);
                pos = f;
            } else {
                if (i) ans += abs(pos - f);
                pos = l;
            }
            ans += i == 0 ? l
                          : l - f;
        }
    }
    cout << ans + d;
}
