#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, k; cin>>n>>k;
        if(n == 4 && k == 3) cout << "-1\n";
        else if(k == 0) {
            for (int i = 0; i < n/2; ++i) {
                cout << i << " " << n-i-1 << "\n";
            }
        }
        else if(k != n-1) {
            cout << 0 << " " << n-k-1 << "\n";
            cout << n-1 << " " << k << "\n";
            for (int i = 1; i < n/2; ++i) {
                if(i == k || i == n-k-1) continue;
                cout << i << " " << n-i-1 << "\n";
            }
        }
        else {
            cout << n-1 << " " << n-2 << "\n";
            cout << "1 " << n-3 << "\n";
            cout << "2 0" << "\n";
            for (int i = 3; i < n/2; ++i) {
                cout << i << " " << n-i-1 << "\n";
             }
        }
    }
}
