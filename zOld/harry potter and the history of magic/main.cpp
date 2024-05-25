#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> y(n); bool ans = true;
    for (int i = 0; i < n; ++i) cin>>y[i];
    int mn = 1000, mx = 2011;
    for (int i = 0; i < n; ++i) {
        int k = 1000;
        while(k > 0) {
            int x = (y[i] / k) % 10;
            for (int j = (k == 1000 ? 1 : 0); j < x; ++j) {
                if(y[i] - x*k + j*k >= mn) {
                    y[i] = y[i] - x*k + j*k;
                    goto p;
                }
            }
            k /= 10;
        }
        k = 1;
        while(k < 1e4) {
            int x = (y[i] / k) % 10;
            for (int j = x; j < 10; ++j) {
                if(y[i] - x*k + j*k >= mn) {
                    y[i] = y[i] - x*k + j*k;
                    goto p;
                }
            }
            k *= 10;
        }
        p:
        if(y[i] < mn || y[i] > mx) ans = false;
        mn = y[i];
    }
    if(ans) for(int x: y) cout << x << "\n";
    else cout << "No solution";
}
