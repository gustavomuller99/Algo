#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x, idx;
        cin >> n >> k;
        idx = n;
        vector<int> a(n), pos;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i == k - 1) x = a[i];
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] > x) {
                idx = i;
                break;
            }
        }
        if (idx > k - 1) cout << idx - 1;
        else {
            swap(a[k - 1], a[idx]);
            int cnt = idx > 0;
            for (int i = idx + 1; i < n; ++i) {
                if (a[i] > x) break;
                cnt++;
            }
            cout << max(cnt, idx - 1);
        }
        cout << "\n";
    }
}
