#include <iostream>
using namespace std;
#define ll long long

int main() {
    int t; cin>>t;
    while(t--) {
        ll a, b, l = 0, r = 1e9+1; cin>>a>>b;
        while(l + 1 < r) {
            ll mid = l + (r-l) / 2;
            if(a - mid >= 0 && b - mid >= 0 && ((a - mid) + (b - mid)) / 2 >= mid) l = mid;
            else r = mid;
        }
        cout << l << "\n";
    }
}
