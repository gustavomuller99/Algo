#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll n; cin>>n;
        while(n % 2 || n < 6) n++;
        cout << (ll) (n * 2.5) << "\n";
    }
}
