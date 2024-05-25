#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2) cout << "NO\n";
        else {
            string ans;
            for (int i = 0; i < n / 2; ++i) {
                for (int j = 0; j < 2; ++j) ans.push_back(i % 26 + 'A');
            }
            cout << "YES\n" << ans << "\n";
        }
    }
}
