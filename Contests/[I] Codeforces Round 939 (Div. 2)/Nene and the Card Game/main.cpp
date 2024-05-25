#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<int> c(3);
        for (int i = 1; i <= n; ++i) c[cnt[i]]++;
        cout << c[2] << "\n";
    }
}
