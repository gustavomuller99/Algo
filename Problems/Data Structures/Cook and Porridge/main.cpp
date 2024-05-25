#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1945/problem/G

#define ll long long

struct Student {
    ll k;
    ll s;
    ll tin = 0;

    bool operator<(const Student &other) const {
        if (k == other.k) {
            if (tin == other.tin) {
                return s > other.s;
            }
            return tin > other.tin;
        }
        return k < other.k;
    }
};

ll n, D;
vector<ll> suf;
vector<Student> a;

void solve() {
    cin >> n >> D;
    suf = vector<ll>(n);
    a = vector<Student>(n);
    priority_queue<Student> pq;
    vector<vector<Student>> ret(D);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].k >> a[i].s;
    }
    suf[n - 1] = a[n - 1].k;
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = max(a[i].k, suf[i + 1]);
    }

    ll cur = 0, ans;
    for (ll t = 0; t < D; ++t) {
        if (!pq.empty() && pq.top().k > suf[cur]) {
            auto top = pq.top();
            pq.pop();
            if (t + top.s < D) ret[t + top.s].push_back(top);
        } else {
            if (t + a[cur].s < D) ret[t + a[cur].s].push_back(a[cur]);
            cur++;
            if (cur == n) {
                ans = t + 1;
                break;
            }
        }
        for (auto r : ret[t]) pq.push({r.k, r.s, t});
    }

    if (cur != n) cout << "-1\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
