#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a, c;

    for (int i = 0; i < n / k + (n % k != 0); ++i) {
        for (int j = min(n, k / 2 + k * i); j > k * i && a.size() < n; --j) {
            a.push_back(j);
            c.push_back(i + 1);
        }
        for (int j = min(n, k + k * i); j > k / 2 + k * i && a.size() < n; --j) {
            a.push_back(j);
            c.push_back(i + 1);
        }
    }

    for(int i : a) cout << i << " ";
    cout << "\n" << n / k + (n % k != 0) << "\n";
    for(int i : c) cout << i << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
