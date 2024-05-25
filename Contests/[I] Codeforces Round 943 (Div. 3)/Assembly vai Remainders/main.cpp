#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m = 501;
        cin >> n;
        vector<int> x(n - 1), a;
        for (int i = 0; i < n - 1; ++i) cin >> x[i];
        a.push_back(m);
        for (int i = 0; i < n - 1; ++i) {
            m += x[i];
            a.push_back(m);
        }
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
