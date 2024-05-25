#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/344975/problem/A

int main() {
    int t; cin>>t; while(t--) {
        int n, ans; cin>>n;
        cin>>ans;
        for (int i = 0; i < n-1; ++i) {
            int x; cin>>x; ans &= x;
        }
        cout << ans << "\n";
    }
}
