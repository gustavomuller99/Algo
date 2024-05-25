#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> x(3e5+1);
    for (int i = 1; i < 3e5+1; ++i) x[i] = i ^ x[i-1];
    int t; cin>>t; while(t--) {
        int a, b, ans=0; cin>>a>>b;
        ans += a;
        if(x[a-1] != b) ans += 1 + ((x[a-1] ^ b) == a);
        cout << ans << "\n";
    }
}
