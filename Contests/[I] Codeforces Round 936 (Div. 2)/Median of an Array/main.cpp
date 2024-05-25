#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 1; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        std::sort(a.begin(), a.end());
        for (int i = (n + 1) / 2; i < n; ++i) {
            if (a[i - 1] == a[i]) ans++;
            else break;
        }
        cout << ans << "\n";
    }
}
