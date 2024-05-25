#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/gym/344975/problem/J

int solve(int bit, const set<int>& a) {
    if (bit < 0) return a.size();
    set<int> s0, s1;
    for (int x : a) {
        if (x & (1 << bit)) s0.insert(x);
        else s1.insert(x);
    }
    if (s0.empty()) return solve(bit - 1, s1);
    else if (s1.empty()) return solve(bit - 1, s0);
    else return 1 + max(solve(bit - 1, s0), solve(bit - 1, s1));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, maxv = 0, bit = -1;
    cin >> n;
    set<int> a;
    for (int i = 0; i < n; ++i) {
        int x; cin>>x; a.insert(x);
        maxv = max(maxv, x);
    }
    while(maxv) bit++, maxv /= 2;
    cout << n - solve(bit, a);
}
