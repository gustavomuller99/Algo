#include <bits/stdc++.h>

using namespace std;
#define ll long long

// https://codeforces.com/gym/344975/problem/H

ll maxv = 0, n, m, k;
vector<ll> a;
vector<vector<ll>> d;
map<pair<int, int>, ll> p;

int main() {
    cin >> n >> m >> k;
    a.resize(n);
    d.resize(1 << n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        p[{u, v}] = c;
    }
    queue<int> q;
    vector<bool> in(1 << n);
    for (int i = 0; i < n; ++i) q.push(1 << i), in[1 << i] = true;
    while (!q.empty()) {
        int cval = q.front();
        q.pop();
        in[cval] = false;
        q.empty();
        for (int i = 0; i < n; ++i) {
            if(!(cval & (1 << i))) continue;
            for (int j = 0; j < n; ++j) {
                if (!(cval & (1 << j))) {
                    int nxt = cval + (1 << j);
                    d[nxt][j] = max(d[nxt][j], d[cval][i] + p[{i, j}]);
                    if (!in[nxt])
                        q.push(nxt),
                        in[nxt] = true;
                }
            }
        }
    }
    for (int i = 0; i < 1 << n; ++i) {
        if (__builtin_popcount(i) == m) {
            ll sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) sum += a[j];
            }
            for (int j = 0; j < n; ++j) {
                maxv = max(maxv, d[i][j] + sum);
            }
        }
    }
    cout << maxv;
}
