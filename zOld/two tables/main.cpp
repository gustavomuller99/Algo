#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int W,H,x1,y1,x2,y2,w,h; cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
        if(w + (x2 - x1) > W && h + (y2 - y1) > H) cout << "-1\n";
        else {
            double ans = INT_MAX;
            if(w + (x2 - x1) <= W) ans = min(max(0, w-x1), max(0, x2-(W-w)));
            if(h + (y2 - y1) <= H) ans = min(ans, (double) min(max(0, h-y1), max(0, y2-(H-h))));
            cout << setprecision(20) << ans << "\n";
        }
    }
}
