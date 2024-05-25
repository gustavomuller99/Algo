#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/344975/problem/B

unsigned long long mod = 1e9+7;
int main() {
    int t; cin>>t; while(t--) {
        unsigned long long n, k, ans = 1; cin>>n>>k;
        for (int i = 0; i < k; ++i) {
            ans *= n;
            ans %= mod;
        }
        cout << ans << "\n";
    }
}
