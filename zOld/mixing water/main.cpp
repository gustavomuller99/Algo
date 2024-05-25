#include <bits/stdc++.h>
using namespace std;
double h,c,tmp;
double f(int x) {
    return (((x+1)/2)*h + (x/2)*c)/x;
}
double d(int x) {
    return abs(tmp - f(x));
}
int main() {
    int t; cin>>t; while(t--) {
        cin>>h>>c>>tmp;
        int l = 1, r = 1e7;
        double b = abs(tmp - (h/2 + c/2));
        while(l + 1 < r) {
            int mid = (l+r)/2;
            if(f(2*mid-1) - tmp > 1e-8) l = mid;
            else r = mid;
        }
        l = 2*l-1, r = 2*r-1;
        int d1 = abs(((l+1)/2)*h + (l/2)*c - tmp*(l))*r;
        int d2 = abs(((r+1)/2)*h + (r/2)*c - tmp*(r))*l;
        if(b < d(l) && b < d(r)) {
            cout << "2\n";
        } else if(d1 <= d2) {
            cout << l << "\n";
        } else cout << r << "\n";
    }
}
