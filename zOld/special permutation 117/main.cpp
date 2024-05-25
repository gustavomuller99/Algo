#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, a, b; cin>>n>>a>>b; a--, b--;
        vector<int> c(n);
        if(b - (a < b) + 1 < n/2 || n - a - 1 - (b > a) + 1 < n/2) cout << "-1\n";
        else {
            cout << a+1 << " ";
            for (int i = n-1; i >= 0; --i) {
                if(i != a && i != b) cout << i+1 << " ";
            }
            cout << b+1 << "\n";
        }
    }
}
