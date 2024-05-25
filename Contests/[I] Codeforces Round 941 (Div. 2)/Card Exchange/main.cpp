#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> cnt(101);
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
            diff++;
        }
        int b = 0;
        for (int i = 0; i < 101; ++i) {
            if (cnt[i] >= k) b++;
        }
        if (b) cout << k - 1 << "\n";
        else cout << diff << "\n";
    }
}
