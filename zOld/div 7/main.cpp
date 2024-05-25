#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        if (((n - n%7) / 10) % 10 == (n / 10) % 10) cout << n - n%7;
        else cout << n + 7 - n%7;
        cout << "\n";
    }
}
