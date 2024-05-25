#include <bits/stdc++.h>

using namespace std;
vector<int> d_odd, d_even;
#define ll unsigned long long

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

void manacher(string s) {
    string t;
    for (auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    d_odd = d_even = vector<int>(s.size() + 1);
    for (int i = 0; i < res.size(); ++i) {
        if (i % 2) d_odd[(i - 1) / 2] = res[i] / 2;
        else d_even[i / 2] = (res[i] - 1) / 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        manacher(s);
        vector<int> dist_e(s.size(), -1), dist_a(s.size(), -1);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) dist_e[i] = i;
            else dist_e[i] = dist_e[i - 1];
            if (i > 1 && s[i] != s[i - 2]) dist_a[i] = i;
            else dist_a[i] = dist_a[i - 1];
        }
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            ll ans, sz = r - l + 1;
            if (dist_e[r] <= l) {
                ans = 0;
            } else if (dist_a[r] <= l + 1) {
                ans = (2 + (sz - 2 + sz % 2)) * ((sz - 1) / 2) / 2;
            } else {
                ans = (1 + (sz - 1)) * (sz - 1) / 2 - 1;
            }
            if (sz % 2 && d_odd[(r + l + 1) / 2] * 2 - 1 < sz ||
                sz % 2 == 0 && d_even[(r + l + 1) / 2] * 2 < sz)
                ans += sz;
            cout << ans << "\n";
        }
    }
}
