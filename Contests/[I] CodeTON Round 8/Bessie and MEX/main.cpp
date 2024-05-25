#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> p, occur(n, 1);
        int mx = n;
        for (int i = n - 1; i >= 0; --i) {
            p.push_back(mx - a[i]);
            occur[mx - a[i]]--;
            if (mx - a[i] < mx) mx = mx - a[i];
        }
        for (auto i = p.rbegin(); i != p.rend(); ++i) {
            cout << *i << " ";
        }
        cout << "\n";
    }
}
