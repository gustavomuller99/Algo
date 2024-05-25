#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, m = 1; cin>>n;
        while(m < n-1) m*=2; if(m > n-1) m/=2;
        for (int i = 1; i < m; ++i) cout << i << " ";
        cout << 0 << " " << m << " ";
        for (int i = m+1; i < n; ++i) cout << i << " ";
        cout << "\n";
    }
}
