#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, d1, d2, d3, d4;
        cin >> n >> m;
        cout << "? 1 1\n"; cout.flush();
        cin >> d1;
        int x1 = d1 + 1 > m ? d1 + 2 - m: 1, y1 = min(m, d1 + 1);
        int x2 = min(n, d1 + 1), y2 = d1 + 1 > n ? d1 + 2 - n : 1;
        cout << "? " << x1 << " " << y1 << "\n"; cout.flush();
        cin >> d2;
        cout << "? " << x2 << " " << y2 << "\n"; cout.flush();
        cin >> d3;
        cout << "? " << x1 + d2 / 2 << " " << y1 - d2 / 2 << "\n"; cout.flush();
        cin >> d4;
        if (d4 == 0)
            cout << "! " << x1 + d2 / 2 << " " << y1 - d2 / 2 << "\n";
        else
            cout << "! " << x2 - d3 / 2 << " " << y2 + d3 / 2 << "\n";
    }
}
