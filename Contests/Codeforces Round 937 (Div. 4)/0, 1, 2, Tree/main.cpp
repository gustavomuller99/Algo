#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, ans = 0, cur = 1, ncur;
        cin >> a >> b >> c;
        while (true) {
            ncur = 0;
            if (a) {
                ncur += 2 * min(a, cur);
                int diff = max(0, a - cur);
                cur -= min(cur, a);
                a = diff;
            }
            if (!a && b) {
                ncur += min(b, cur);
                int diff = max(0, b - cur);
                cur -= min(cur, b);
                b = diff;
            }
            if (!a && !b && c) {
                int diff = max(0, c - cur);
                cur -= min(cur, c);
                c = diff;
            }
            if (cur > 0 || ncur == 0 || (!a && !b && !c)) break;
            cur = ncur;
            ans++;
        }
        if (cur > 0 || ncur || a || b || c) cout << "-1\n";
        else cout << ans << "\n";
    }
}
