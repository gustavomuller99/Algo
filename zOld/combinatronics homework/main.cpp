#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int m, cnt=0;
        vector<int> a(3); cin>>a[0]>>a[1]>>a[2]>>m;
        sort(a.begin(), a.end());
        if(m <= (a[0]+a[1]+a[2]-3) && m >= a[2]-1-(a[0]+a[1])) cout << "YES\n";
        else cout << "NO\n";
    }
}
