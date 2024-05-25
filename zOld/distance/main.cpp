#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int x, y; cin>>x>>y;
        if((x + y) % 2) cout << "-1 -1\n";
        else {
            cout << x/2 + x%2 << " " << y/2 << "\n";
        }
    }
}
