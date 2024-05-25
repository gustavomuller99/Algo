#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main() {
    int t; cin>>t; while(t--) {
        ll a,b,x; cin>>a>>b>>x;
        bool ans = false;
        while(a >= x || b >= x) {
            if(a == 0 || b == 0) break;
            if(max(a, b) % min(a, b) == x % min(a, b)) ans = true;
            if(a > b) a = a % b;
            else b = b % a;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
