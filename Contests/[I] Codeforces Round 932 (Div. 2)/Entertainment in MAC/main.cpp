#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, r;
        int n;
        cin >> n >> s;
        for (int i = 0; i < s.size(); ++i) {
            r.push_back(s[s.size() - i - 1]);
        }
        if (s <= r) {
            if (n % 2) cout << s + r;
            else cout << s;
        } else {
            if (n % 2) cout << r;
            else cout << r + s;
        }
        cout << "\n";
    }
}
