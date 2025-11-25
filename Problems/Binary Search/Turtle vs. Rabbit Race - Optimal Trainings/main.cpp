#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> a;

ll f(int l, int r, ll u) {
    int s = a[r] - (l ? a[l - 1] : 0);
    ll uf = (u + 1 - s);
    return (u - uf + 1) * (u + uf) / 2;
}

void solve() {
    int n;
    cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) a[i] += a[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;
        l--;
        int l1 = l, r1 = n - 1;
        while (r1 > l1 + 2) {
            int m1 = l1 + (r1 - l1) / 3;
            int m2 = r1 - (r1 - l1) / 3;
            if (f(l, m1, u) < f(l, m2, u)) l1 = m1;
            else r1 = m2;
        }
        int r_ans = r1;
        for (int i = r1; i >= l1; --i) {
            if (f(l, i, u) >= f(l, r_ans, u)) r_ans = i;
        }
        cout << r_ans + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
