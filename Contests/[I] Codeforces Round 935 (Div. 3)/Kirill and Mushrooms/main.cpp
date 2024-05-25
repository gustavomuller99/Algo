#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll val = 0, el = 0;
        cin >> n;
        vector<int> a(n), v(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[i] = a[x - 1];
        }
        multiset<ll> s;
        for (int i = n - 1; i >= 0; --i) {
            s.insert(v[i]);
            int k = i + 1;
            while (s.size() > k) s.erase(s.find(*s.begin()));
            if (s.size() == k && *s.begin() * s.size() >= val) val = *s.begin() * s.size(), el = k;
        }
        cout << val << " " << el << "\n";
    }
}
