#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

// https://codeforces.com/contest/1944/problem/F1
//    a b c
//    b <= c + a
//    a >= b - c
//
//    0 0 i ... n 0 0
//
//    d[x][y] -> last two elements
//    prev[a][b] -> sum of d[0..a][b]
//
//    for c 0..k
//    if (c < b) new_d[b][c] += prev[k][b] - prev[b - c][b]
//            else new_d[b][c] += prev[k][b]

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n, k, p;
        cin >> n >> k >> p;
        vector<vector<ll>> d(k + 1, vector<ll> (k + 1));
        vector<vector<ll>> prev(k + 1, vector<ll> (k + 1));
        vector<vector<ll>> nd(k + 1, vector<ll> (k + 1));
        d[0][0] = 1;
        for (int i = 0; i < n + 2; ++i) {
            for (int b = 0; b <= k; ++b) {
                prev[0][b] = d[0][b];
                for (int a = 1; a <= k; ++a) {
                    prev[a][b] = (prev[a - 1][b] + d[a][b]) % p;
                }
            }
            for (int b = 0; b <= k; ++b) {
                for (int c = 0; c <= k; ++c) {
                    if (c < b) nd[b][c] = (prev[k][b] - prev[b - c - 1][b] + p) % p;
                    else nd[b][c] = (prev[k][b]) % p;
                }
            }
            d = nd;
        }
        cout << d[0][0] % p << "\n";
    }
}
