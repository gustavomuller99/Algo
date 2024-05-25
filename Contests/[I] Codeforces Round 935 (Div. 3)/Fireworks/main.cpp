#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, m;
        cin >> a >> b >> m;
        cout <<  (m + 1) / a + (m + 1) / b + ((m + 1) % a != 0) + + ((m + 1) % b != 0) << "\n";
    }
}
