#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, bit = 0;
        cin >> n;
        while(1 << bit <= n) bit++;
        if (n == (1 << bit) - 1) {
            int h = 1;
            for (int i = 2; i*i <= n; ++i) {
                if (n % i == 0) {
                    h = (n / i);
                    break;
                }
            }
            cout << h;
        }
        else cout << ((1 << bit) - 1);
        cout << "\n";
    }
}
