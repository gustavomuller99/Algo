#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i = 0, idx = 0;
        string a, b;
        cin >> n >> m >> a >> b;
        while(idx < m && i < n) {
            if (b[idx] == a[i]) i++;
            idx++;
        }
        cout << i << "\n";
    }
}
