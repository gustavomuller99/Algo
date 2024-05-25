#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> z;

vector<int> z_function() {
    int n = s.size();
    z = vector<int>(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int cnt(int x) {
    int r = 1;
    for (int i = x; i < s.size(); ++i) {
        if (z[i] >= x) r++, i += x - 1;
    }
    return r;
}

/* k * lcp <= n,
 * k <= sqrt(n)
 * k > sqrt(n) -> l <= sqrt(n) */

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r >> s;
        z_function();
        vector<int> ans(n + 1);
        for (int k = 1; k * k <= n; ++k) {
            int l1 = 0, r1 = n + 1;
            while (l1 + 1 < r1) {
                int mid = (l1 + r1) / 2;
                if (cnt(mid) >= k) l1 = mid;
                else r1 = mid;
            }
            ans[k] = l1;
        }
        for (int lcp = 1; lcp * lcp <= n; ++lcp) {
            int c = cnt(lcp);
            ans[c] = max(lcp, ans[c]);
        }
        for (int i = n - 1; i >= 0; --i) ans[i] = max(ans[i], ans[i + 1]);
        for (int i = l; i <= r; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
