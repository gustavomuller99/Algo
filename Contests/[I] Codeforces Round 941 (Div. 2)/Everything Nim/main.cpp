#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, bool> m;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (!m[x]) a.push_back(x), m[x] = true;
        }
        sort(a.begin(), a.end());
        bool al = true;
        if (a[0] == 1) {
            for (int i = 1; i < a.size(); ++i) {
                if (a[i] - a[i - 1] > 1) {
                    if (i % 2) al = false;
                    break;
                }
                if (i == a.size() - 1 && i % 2) al = false;
            }
        }
        if (al) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
