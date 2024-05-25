#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if (k == n) cout << "YES\n1\n1\n";
        else if (k > n || (k < n && 2 * k > n + 1)) cout << "NO\n";
        else {
            cout << "YES\n2\n";
            cout << n - k + 1 << " " << 1 << "\n";
        }
    }
}
