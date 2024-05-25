#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

string solve() {
    long long k, x, a;
    long long loss = 0;
    cin >> k >> x >> a;
    for (int i = 0; i <= x; ++i) {
        long long y = ceil((double) loss / (double) (k - 1));
        y += (y * (k - 1) == loss);
        if (loss + y > a) return "NO\n";
        loss += y;
    }
    return "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve();
    }
}
