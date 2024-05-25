#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> z;

vector<int> z_function() {
    int n = s.size();
    z = vector<int> (n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int cnt(int x) {
    int r = 1;
    for (int i = x; i < s.size(); ++i) {
        if (z[i] >= x) r++, i += x - 1;
    }
    return r;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r >> s;
        z_function();
        int l1 = 0, r1 = n + 1;
        while (l1 + 1 < r1) {
            int mid = (l1 + r1) / 2;
            if (cnt(mid) >= l) l1 = mid;
            else r1 = mid;
        }
        cout << l1 << "\n";
    }
}
