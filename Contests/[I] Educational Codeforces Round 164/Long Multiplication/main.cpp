#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        int c = 0;
        for (int i = 0; i < x.size(); ++i) {
            if (c == 0 && x[i] > y[i]) c = 1;
            else if (c == 0 && x[i] < y[i]) c = 2;
            else if (c == 1 && x[i] > y[i]) swap(x[i], y[i]);
            else if (c == 2 && x[i] < y[i]) swap(x[i], y[i]);
        }
        cout << x << "\n" << y << "\n";
    }
}
