#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; long long ans=0; cin>>n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        sort(a.begin(), a.end());
        int i;
        for (i = 0; i < n; ++i) {
            if(i == n-1 || a[i+1] - (a[i] - ans) - ans < a[i] - ans) break;
            ans += (a[i] - ans);
        }
        cout << a[i] - ans << "\n";
    }
}
