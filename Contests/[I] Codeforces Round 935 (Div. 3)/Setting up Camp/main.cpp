#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < (3 - (b % 3)) % 3) cout << "-1\n";
        else cout << a + (b + c) / 3 + ((b + c) % 3 != 0) << "\n";
    }
}
