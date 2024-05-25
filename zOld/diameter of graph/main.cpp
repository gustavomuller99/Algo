#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll n, m; long long k; cin>>n>>m>>k; k-=2;
        if(k < 0 ||
            m < n-1 ||
            m > n*(n-1)/2 ||
            k == 0 && n > 1 ||
            k == 1 && n > 2 && m != n*(n-1)/2) cout << "NO\n";
        else cout << "YES\n";
    }
}
