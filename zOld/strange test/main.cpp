#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int a, b; cin>>a>>b;
        int ans = INT_MAX;
        for (int i = 0; i <= b; ++i) {
            if((i | b) == b) ans = min(ans, abs(i - a) + (i != b));
        }
        cout << ans << "\n";
    }
}
