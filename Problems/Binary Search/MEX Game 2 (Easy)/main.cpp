#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;
vector<int> a;
int m, k;

// https://codeforces.com/contest/1943/problem/E1

/** for fixed MEX x:
 * alice always chose the smallest f
 * fix index of frequencies (0..x-1) that should be minimized
 * simulate, making fixed indexed as small as possible, checking if <= k at the end */

bool f(int x) {
    vector<int> b;
    for (int i = 0; i < x; ++i) {
        b.push_back(a[i]);
    }
    std::sort(b.begin(), b.end());
    for (int fix = 1; fix < x; ++fix) {
        deque<ll> c;
        for (int i = 0; i <= fix; ++i) c.push_back(b[i]);

        while (c.size() != 2) {

            c.pop_front();
            ll sz = c.size(), spent = 0, last = c.size() - 1;

            for (int i = c.size() - 2; i >= 0; --i) {
                spent += (c[i + 1] - c[i]) * (sz - i - 1);
                if (spent >= k) {
                    spent -= (c[i + 1] - c[i]) * (sz - i - 1);
                    break;
                }
                last = i;
            }

            for (int i = last; i < c.size(); ++i) {
                c[i] = c[last];
            }

            ll left = k - spent;

            for (int i = last; i < c.size(); ++i) {
                c[i] -= left / (sz - last);
            }

            left %= (sz - last);
            for (int i = last; i < c.size(); ++i) {
                if (left) {
                    left--;
                    c[i]--;
                }
            }

        }
        c.pop_front();
        if (c[0] <= k) return false;
    }
    return true;
}

void solve() {
    cin >> m >> k;
    a = vector<int>(m + 1);
    for (int i = 0; i < m + 1; ++i) {
        cin >> a[i];
    }
    int l = 0, r = m + 2;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (f(mid)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
