#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n,l,r,k,ans=0; cin>>n>>l>>r>>k;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x; cin>>x;
            if(x >= l && x <= r) a.push_back(x);
        }
        sort(a.begin(), a.end());
        for (int i : a) {
            if(k < i) break;
            k -= i; ans++;
        }
        cout << ans << "\n";
    }
}
