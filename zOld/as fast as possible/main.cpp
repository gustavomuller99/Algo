#include <bits/stdc++.h>
using namespace std;
int n, k; double l,v1,v2;
bool f(double t) {
    double d = 0, tt = 0; int p = n;
    while(p > 0 && d < l) {
        p -= k;
        double lx = d, rx = l;
        for (int i = 0; i < 100; ++i) {
            double mid = (lx + rx) / 2;
            if((tt + (mid - d) / v2 + (l - mid) / v1) < t) rx = mid;
            else lx = mid;
        }
        tt += (rx - d) / v2;
        d += ((rx - d) / v2) * v1;
    }
    return tt < t;
}
int main() {
    cin>>n>>l>>v1>>v2>>k;
    double lx = 0, rx = 1e9+1;
    for (int i = 0; i < 100; ++i) {
        double mid = (lx + rx) / 2;
        if(f(mid)) rx = mid;
        else lx = mid;
    }
    cout << setprecision(20) << rx;
}
