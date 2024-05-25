#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, m, rb, cb, rd, cd; cin>>n>>m>>rb>>cb>>rd>>cd;
        int tr = abs(rb - rd) + (rb > rd ? 2*(n-rb) : 0);
        int tc = abs(cb - cd) + (cb > cd ? 2*(m-cb) : 0);
        cout << min(tr, tc) << "\n";
    }
}
