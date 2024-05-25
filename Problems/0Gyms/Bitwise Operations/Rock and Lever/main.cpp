#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/344975/problem/C

int main() {
    int t; cin>>t; while(t--) {
        unsigned long long n, ans=0; cin>>n;
        vector<int> a(32);
        for (int i = 0; i < n; ++i) {
            int x, k = 0; cin>>x;
            while(x >= (1 << k)) k++;
            ans += a[k-1];
            a[k-1]++;
        }
        cout << ans << "\n";
    }
}
