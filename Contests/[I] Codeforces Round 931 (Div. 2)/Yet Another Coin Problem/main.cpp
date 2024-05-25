#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> c = {1, 3, 6, 10};
        vector<int> d(30, INT_MAX);
        d[0] = 0;
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i == c[j]) d[i] = 1;
                if (i > c[j]) d[i] = min(d[i], d[i - c[j]] + 1);
            }
        }
        cout << min(n / 15 + d[n % 15], n > 15 ? (n / 15) - 1 + d[n % 15 + 15] : INT_MAX) << "\n";
    }
}
