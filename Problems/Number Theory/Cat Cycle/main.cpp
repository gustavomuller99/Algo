#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, k; cin>>n>>k;
        cout << (k - 1 + (n % 2 ? k / (n / 2) - (k % (n / 2) == 0) : 0)) % n + 1 << "\n";
    }
}
