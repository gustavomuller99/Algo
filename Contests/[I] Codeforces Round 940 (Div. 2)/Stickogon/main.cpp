#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        vector<int> l(101);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            l[x]++;
        }
        for (int i = 0; i < l.size(); ++i) {
            ans += l[i] / 3;
        }
        cout << ans << "\n";
    }
}
